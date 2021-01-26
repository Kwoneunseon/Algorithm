//bfs로 문제를 풀었는데
//dfs를 사용해야 할듯.
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool visit[100][100] = { false };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int row, col,cnt = 0;
vector< vector<int> >miro;

int bfs(int a, int b) {
	int x, y, next_x, next_y;
	queue<pair<int, int> >q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		cnt++;
		q.pop();
		if (x == row - 1 && y == col - 1) {
			return cnt;
		}
			for (int i = 0; i < 4; i++)
			{
				next_x = x + dx[i];
				next_y = y + dy[i];
				if (next_x < row && next_x >= 0 && next_y < col && next_y >= 0 && !visit[next_x][next_y]) {
					if (miro[next_x][next_y] == 1) {
						q.push(make_pair(next_x, next_y));
					}
					visit[next_x][next_y] = true;
				}
			}
	}
	return cnt;
}

int main() {
	int num;
	string str_num;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		vector<int> temp;
		cin >> num;
		str_num = to_string(num);
		for (int j = 0; j < col; j++)
		{
			temp.push_back(str_num[j]-'0');
		}
		miro.push_back(temp);
	}

	cout << bfs(0, 0);


	return 0;
}