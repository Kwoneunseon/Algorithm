//2583
//bfs
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[100][100] = { false, };
int map[101][101] = { 0, };
int row, col, k;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int a, int b) {
	int x, y, next_x, next_y, cnt = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col && !visit[next_x][next_y]) {
				if (map[next_x][next_y] != 1) {
					q.push(make_pair(next_x, next_y));
					visit[next_x][next_y] = true;
				}
			}

		}
	}
	return cnt;
}

int main() {
	cin >> row >> col >> k;
	vector<int>answer;
	int first_x, first_y, second_x, second_y;
	for (int i = 0; i < k; i++)
	{
		//행렬로 바꿔서 입력받는다.
		cin >> first_y >> first_x >> second_y >> second_x;

		for (int j = first_x; j < second_x; j++)
		{
			for (int k = first_y; k < second_y; k++)
			{
				map[j][k] = 1;
			}
		}
	}
	//bfs탐색
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] != 1 && !visit[i][j]) {
				answer.push_back(bfs(i, j));
			}
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}