//2206
//bfs»ç¿ë
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1002

using namespace std;

long long visit[MAX][MAX][2] = { 0, };
long long map[MAX][MAX] = { 0, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int row, col;


int bfs(int destination_x, int destination_y) {
	int x, y, next_x, next_y,block;
	queue<pair<pair<int, int>, int> > q;//x,y¿Í block
	q.push(make_pair(make_pair(1, 1), 1));
	visit[1][1][1] = 1;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		block = q.front().second;
		q.pop();
		if (x == destination_x && y == destination_y) {
			return visit[destination_x][destination_y][block];
		}

		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x >= 1 && next_x <= row && next_y >= 1 && next_y <= col) {
				if (map[next_x][next_y] == 1 && block == 1) {
					visit[next_x][next_y][block - 1] = visit[x][y][block] + 1;
					q.push(make_pair(make_pair(next_x, next_y), block - 1));
				}
				else if (map[next_x][next_y] == 0 && visit[next_x][next_y][block] == 0) {
					visit[next_x][next_y][block] = visit[x][y][block] + 1;
					q.push(make_pair(make_pair(next_x, next_y), block));
				}
			}
		}
	}
	return -1;
}

int main() {

	string temp;
	cin >> row >> col;
	for (int i = 1; i <=row; i++)
	{
		cin >> temp;
		for (int j = 1; j <= col; j++)
		{
			map[i][j] = temp[j-1]-'0';
		}
	}

	cout << bfs(row, col);

	return 0;
}