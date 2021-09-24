#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int visit[21][21] = { 0, };
int map[21][21] = { 0, };
int N;


int bfs(int start_x, int start_y,int fish) {
	int x, y, new_x, new_y,shark,answer=0,count=0;
	queue<pair<pair<int, int>, int> >q;
	q.push({ {start_x,start_y},2 });
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		shark = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			new_x = x + dx[i];
			new_y = y + dy[i];
			if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < N) {
				if (map[new_x][new_y] != 0&&map[new_x][new_y] < shark) {
					count++;
					shark += map[new_x][new_y];
					map[new_x][new_y] = 0;
					visit[new_x][new_y] = visit[x][y] + 1;
					answer = max(answer, visit[new_x][new_y]);
					if (count == fish)
						return answer;
					q.push({ {new_x,new_y},shark });
					break;
				}
				else if (map[new_x][new_y] == 0)
				{
					visit[new_x][new_y] = visit[x][y] + 1;
					q.push({ {new_x,new_y},shark });
				}
			}
		}
	}
	return answer;
}

int main() {
	int x,y,fish=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9) {
				x = i;y = j;
			}
			else if (map[i][j] != 0)
				fish++;
		}
	}

	cout << bfs(x, y, fish);

	return 0;
}