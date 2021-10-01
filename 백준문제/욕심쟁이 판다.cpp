#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int forest[500][500];
int dp[500][500] = { 0, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;

int count(int a, int b) {
	int max_cnt = 1;
	queue<pair<int, int>> q; //판다의 위치 x,y 그리고 움직인 횟수
	q.push({ a,b });
	dp[a][b] = 1;
	int x, y, next_x, next_y, cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		cnt = dp[x][y];
		max_cnt = max(max_cnt, cnt);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
				continue;
			if (forest[next_x][next_y] > forest[x][y]) {

				if (dp[next_x][next_y] == 0 || dp[next_x][next_y] <= cnt + 1) {
					dp[next_x][next_y] = cnt + 1;
					q.push({ next_x,next_y });
				}
			}
		}
	}
	return max_cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> forest[i][j];
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == 0) {
				answer = max(answer, count(i, j));
			}
		}
	}
	cout << answer;

	return 0;
}