#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

bool visit[51][51] = { false, };
int map[51][51] = { 0, };

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int M, N;

void bfs(int row, int col) {
	int x, y, new_x, new_y;
	queue<pair<int, int> >q;
	q.push({ row, col });
	visit[row][col] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			new_x = x + dx[i];
			new_y = y + dy[i];
			if (new_x >= 0 && new_x < M&&new_y >= 0 && new_y < N && !visit[new_x][new_y]) {
				if (map[new_x][new_y] == 1) {
					visit[new_x][new_y] = true;
					q.push({ new_x,new_y });
				}
			}

		}


	}


}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T,K,row,col,count;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		count = 0;
		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < K; i++)
		{
			cin >> row >> col;
			map[row][col] = 1;
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0;  j < N;  j++)
			{
				if (map[i][j] == 1 && !visit[i][j]) {
					count++;
					bfs(i, j);
				}
			}
		}
		cout << count<<"\n";

	}


	return 0;
}