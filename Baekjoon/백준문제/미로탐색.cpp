//2178번
//dfs사용
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int col, row;
bool visit[100][100] = { false, };
vector<vector<int> > miro;
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
int cnt = 1, answer;

void dfs(int x, int y) {
	if (visit[x][y])
		return;
	if (x == row - 1 && y == col - 1)
		answer = cnt;
	visit[x][y] = true;
	cnt++;
	int next_x, next_y;
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];
		if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col) {
			if (miro[next_x][next_y] == 1 && !visit[next_x][next_y]) {
				flag = true;
				dfs(next_x, next_y);
			}
		}
	}
	if (!flag) {
		cnt--;
	}
}

int main() {
	cin >> row >> col;
	string str_num;
	int num;
	for (int i = 0; i < row; i++)
	{
		vector<int>nums;
		cin >> str_num;
		for (int j = 0;j < col; j++)
		{
			nums.push_back(str_num[j] - '0');
		}
		miro.push_back(nums);
	}

	dfs(0, 0);

	cout << answer;


	return 0;
}