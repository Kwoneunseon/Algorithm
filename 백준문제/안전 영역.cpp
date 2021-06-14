//2468
//bfs »ç¿ë

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int> > safe_zone;
bool visit[100][100] = { false, };
int N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int a, int b, int rainfall) {
	int x, y, next_x, next_y;
	queue<pair<int,int> >q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x < N&&next_y < N && next_x >= 0 && next_y >= 0 && !visit[next_x][next_y]) {
				if (safe_zone[next_x][next_y] > rainfall) {
					q.push(make_pair(next_x, next_y));
				}
				visit[next_x][next_y] = true;
			}

		}
	}
}

int main() {
	int temp ,max= 0,count=0,max_rain = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int>zone;
		for (int j = 0;  j < N;  j++)
		{
			cin >> temp;
			if (max_rain < temp)
				max_rain = temp;
			zone.push_back(temp);
		}
		safe_zone.push_back(zone);
	}
	
	for (int i = 0; i < max_rain; i++)
	{
		count = 0;
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (!visit[j][k] && safe_zone[j][k] > i) {
					bfs(j, k, i);
					count++;
				}
			}
		}
		if (max < count)
			max = count;
	}
	cout << max;
	return 0;
}
