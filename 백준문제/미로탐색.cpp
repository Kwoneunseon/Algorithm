//2178
//bfs사용
//대표적인 bfs문제 -> 최단 거리를 찾을때 사용됨.
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool visit[100][100] = { false, };
int row, col;
vector<vector<int> > miro;

int bfs(int a, int b,int cnt) {
	int x, y, next_x, next_y;
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(a, b), cnt));
	visit[a][b] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second ;
		q.pop();
		if (x == row - 1 && y == col - 1)
			return cnt;
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x < row&&next_x >= 0 && next_y < col&&next_y >= 0 && !visit[next_x][next_y]) {
				visit[next_x][next_y] = true;
				if(miro[next_x][next_y]==1)
					q.push(make_pair(make_pair(next_x, next_y), cnt+1));
			}
		}

	}
	return cnt;

}

int main() {
	cin >> row >> col;
	string s_num;
	for (int i = 0; i < row; i++)
	{
		vector<int>nums;
		cin >> s_num;
		for (int j = 0; j < col; j++)
		{
			nums.push_back(s_num[j] - '0');
		}
		miro.push_back(nums);
	}

	cout << bfs(0, 0,1);


	return 0;
}