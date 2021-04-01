#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
bool visit[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;

void bfs_ground(int a, int b, int count) {
	queue<pair<int, int> >q;
	int x, y, next_x, next_y;
	x = a, y = b;
	q.push({ a,b });
	visit[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		map[x][y] = count;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !visit[next_x][next_y]) {
				if (map[next_x][next_y] == 1) {
					visit[next_x][next_y] = true;
					q.push({ next_x,next_y });
				}
			}
		}
	}
}

int bfs_bridge(int count) {
	queue<pair<int, int> >q;
	int distance = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == count) {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	int x, y, next_x, next_y, queue_size;
	while (!q.empty()) {
		queue_size = q.size();
		//distance를 쉽게 계산하기 위해서 하나씩
		for (int i = 0; i < queue_size; i++)
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				next_x = x + dx[j];
				next_y = y + dy[j];
				
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !visit[next_x][next_y]) {
					
					if (map[next_x][next_y] == 0) {
						q.push({ next_x,next_y });
						visit[next_x][next_y] = true;
					}
					else if (map[next_x][next_y] != count)
						return distance;
				}
			}
		}
		distance++;
	}
	return 0;
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	memset(visit, false, sizeof(visit));	
	int count = 1;
	//대륙별로 id부여하기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1&&!visit[i][j]) {
				bfs_ground(i, j, count++);
			}
		}
	}

	//대륙사이 가장 짧은 거리 구하기
	int result = 100000;
	for (int i = 1; i < count; i++)
	{
		memset(visit, false, sizeof(visit));
		result = min(result, bfs_bridge(i));
	}

	cout << result;

	return 0;
}

