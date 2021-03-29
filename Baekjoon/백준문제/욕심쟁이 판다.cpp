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
bool visit[500][500] = { false, };

int count(int a, int b) {
	int max_cnt = 1;
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>,int>> q;
	q.push({ { a,b },1 });
	int x, y, next_x, next_y,cnt;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt =  q.front().second;
		max_cnt = max(cnt, max_cnt);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n &&!visit[next_x][next_y]) {				
				if (forest[next_x][next_y] > forest[x][y]) {
					if (dp[next_x][next_y] != 0)
						max_cnt =max(max_cnt, dp[next_x][next_y] + 1);
					else {
						visit[next_x][next_y] = true;
						q.push({ {next_x,next_y},cnt + 1 });
					}
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
			dp[i][j]=count(i, j);
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer;

	return 0;
}