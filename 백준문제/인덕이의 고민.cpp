#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 51

using namespace std;

const long long INF = 9e9;

int N, knife_w, bi_w, rook_w, M;
int answer = INF;

int map[51][51] = { 0, };
long long dist[51][51] = { 0, };
//ㄴ, L형태로 움직임
int knife_x[] = { 2,2,1,1,-1,-1,-2,-2 };
int knife_y[] = { 1,-1,2,-2,2,-2,1,-1 };
//대각선으로 움직임
int bi_x[] = { 1,1,-1,-1 };
int bi_y[] = { 1,-1,1,-1 };
//상하좌우롱 움직임
int rook_x[] = { 1,0,-1,0 };
int rook_y[] = { 0,1,0,-1 };

void dijkstra(long long *dist, const int& start){
	int x, y, new_x, new_y, curDist, pos;
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.emplace(0, start);
	while (!q.empty()) {
		curDist = q.top().first;
		pos = q.top().second;
		x = pos / N;
		y = pos % N;
		q.pop();

		if (dist[pos] < curDist)
			continue;

		//나이프 이동
		for (int i = 0; i < 8; i++)
		{
			new_x = x + knife_x[i];
			new_y = y + knife_y[i];
			if (new_x<0 || new_x >=N || new_y<0 || new_y>=N)
				continue;
			int nextPos = new_x * N + new_y;
			int sum = curDist + knife_w;

			if (sum < dist[nextPos]) {
				dist[nextPos] = sum;
				q.emplace(sum, nextPos);
			}


		}
		//비숍 이동
		for (int j = 1; j < N; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				new_x = x + j* bi_x[i];
				new_y = y + j*bi_y[i];
				if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N)
					continue;
				int nextPos = new_x * N + new_y;
				int sum = curDist + bi_w;

				if (sum < dist[nextPos]) {
					dist[nextPos] = sum;
					q.emplace(sum, nextPos);
				}

			}
		}
		//룩 이동
		for (int j = 1; j < N; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				new_x = x + j*rook_x[i];
				new_y = y + j*rook_y[i];
				if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N)
					continue;
			
				int nextPos = new_x * N + new_y;
				int sum = curDist + rook_w;

				if (sum < dist[nextPos]) {
					dist[nextPos] = sum;
					q.emplace(sum, nextPos);
				}

			}

		}
	}
}

bool visited[5];
void dfs(const vector<int>&pos, int cur, int overload, int cnt) {
	if (cnt == M) {
		answer = min(answer, cnt);
		return;
	}
	for (int i = 1; i <= M ; i++)
	{
		if (visited[i])
			continue;
		
		visited[i] = true;
		dfs(pos, i, overload + dist[cur][pos[i]], cnt + 1);
		visited[i] = false;

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int start_x, start_y, feeds, x, y ;

	cin >> N >>knife_w>>bi_w>>rook_w;
	cin >> start_x >> start_y >> M;
	vector<int>pos(M + 1);
	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y; 
		pos[i] = x * N + y;
	}
	
	for (int i = 0; i <=M; i++)
	{
		dijkstra(dist[i], pos[i]);
	}

	dfs(pos, 0, 0, 0);
	cout << answer;

	return 0;
}