//10026
//bfs
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

bool visit[100][100] = { false, };
char rgb[100][100];

int row;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int a, int b,bool flag) {
	int x, y, next_x, next_y;
	char color = rgb[a][b];
	queue<pair<int, int> >q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		x= q.front().first;
		y = q.front().second;
		q.pop();
		visit[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x < row && next_y < row&&next_x >= 0 && next_y >= 0 && !visit[next_x][next_y]) {
				if (flag) {
					if (color == 'R' || color == 'G') {
						if (rgb[next_x][next_y] == 'R' || rgb[next_x][next_y] == 'G') {
							q.push(make_pair(next_x, next_y));
							visit[next_x][next_y] = true;
						}
					}
					else if(rgb[next_x][next_y]==color) {

						q.push(make_pair(next_x, next_y));
						visit[next_x][next_y] = true;
					}
				}
				else if (rgb[next_x][next_y] == color) {
					q.push(make_pair(next_x, next_y));
					visit[next_x][next_y] = true;
				}
			}
		}
		
	}
}

int main() {
	char color;
	cin >> row;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> color;
			rgb[i][j] = color;
		}
	}
	int cnt=0,flag=false;//적록색약인 사람=true;
	char c[] = { 'R','G','B' };
	for (int time = 0; time < 2; time++)
	{
		int cnt = 0;
		memset(visit, false, sizeof(visit));

		for (int i = 0; i< row; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (visit[i][j] != true) {
					bfs(i, j,flag);
					cnt++;
				}
			}
		}
		flag = true;
		cout << cnt <<" ";
	}

	return 0;
}