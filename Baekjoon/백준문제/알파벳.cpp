//1987
//bfs

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int row, col, answer = 0;
bool visit[26] = { false, };
int map[21][21] = { 0, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt) {
	int next_x, next_y;
	answer = max(answer, cnt);
	for (int i = 0; i < 4; i++)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];
		if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col && !visit[map[next_x][next_y]]) {

			visit[map[next_x][next_y]] = true;
			dfs(next_x, next_y, cnt + 1);
			visit[map[next_x][next_y]] = false; //나왔으니 다시 false처리해줌.
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char temp;
	cin >> row >> col;
	int check[27] = { 0, };
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> temp;
			map[i][j] = temp - 'A';
		}
	}

	visit[map[0][0]] = true;
	dfs(0, 0, 1);
	cout << answer;


	return 0;
}