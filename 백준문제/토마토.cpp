#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<pair<pair<int, int>, int>, int> Info;

int x, y, z;
bool visit[101][101][101] = { false, };
int tomato[101][101][101] = { 0, };

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main() {
	queue<Info>q;
	int count = 0, day = 0, empty = 0,finish_day;
	cin >> x >> y >> z;
	//토마토 입력
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < x; k++)
			{
				cin >> tomato[j][k][i];
				if (tomato[j][k][i] == 1) {
					q.push({ {{j,k},i },day });
					visit[j][k][i] == true;
				}
				else if (tomato[j][k][i] == -1)
					empty++;
			}
		}
	}

	int col, row, height, new_col, new_row, new_height;
	while (!q.empty()) {
		col = q.front().first.first.second;
		row = q.front().first.first.first;
		height = q.front().first.second;
		day = q.front().second;
		finish_day = max(finish_day, day);
		count = count + 1;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			new_col = col + dx[i];
			new_row = row + dy[i];
			new_height = height + dz[i];
			if (new_col >= 0 && new_row >= 0 && new_height >= 0 && new_col < x &&new_row < y&&new_height < z) {
				if (!visit[new_row][new_col][new_height] && tomato[new_row][new_col][new_height]==0) {
					q.push({ {{new_row,new_col},new_height },day+1});
					visit[new_row][new_col][new_height] = true;
				}
			}

		}
	}
	if (count == x * y*z - empty)
		cout << finish_day;
	else
		cout << -1;


	return 0;
}