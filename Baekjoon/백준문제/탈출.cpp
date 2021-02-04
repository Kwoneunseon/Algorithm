//3055
//bfs

#include <iostream>
#include <vector>
#include <queue>
#define max 50
using namespace std;

vector<char>map[max];
bool visit[max][max];
int cnt = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int row, col;

void move_water() {
	int next_x, next_y;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == '*') {
				for (int k = 0; k < 4; k++)
				{
					next_x = i + dx[k];
					next_y = j + dy[k];
					if (next_x >= 0 && next_x < row&&next_y >= 0 && next_y < col){
						if (map[next_x][next_y] == '.')
							map[next_x][next_y] = '*';
					}
				}
			}
		}

	}

}

int bfs(int a, int b) {
	int x, y, next_x, next_y, cnt = 0;
	queue<pair<pair<int,int>,int> >q;
	q.push(make_pair(make_pair(a, b),1));
	visit[a][b] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		move_water(); //물 움직임.
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];

			if (next_x >= 0 && next_x < row&&next_y >= 0 && next_y < col && !visit[next_x][next_y]) {
				if (map[next_x][next_y] == '.') {
					q.push(make_pair(make_pair(next_x, next_y),cnt++));
					visit[next_x][next_y] = true;
				}
				else if (map[next_x][next_y] == 'S')
					return cnt+1;
			}
			
		}
	}





}

int main() {
	char temp;
	int start_x, start_y;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> temp;
			map[i].push_back(temp);
			if (temp == 'D') {
				start_x = i;
				start_y = j;
			}
		}
	}

	cout << bfs(start_x, start_y);

	return 0;
}