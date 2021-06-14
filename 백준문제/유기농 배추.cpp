//1012
//bfs »ç¿ë
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int map[50][50];
bool visit[50][50];
int width, height;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int a, int b) {
	int x, y, next_x, next_y;
	queue<pair<int, int> > q;
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
			if (next_x >= 0 && next_x < height&& next_y >= 0 && next_y < width && !visit[next_x][next_y]) {
				if (map[next_x][next_y] == 1)
					q.push(make_pair(next_x, next_y));
 				visit[next_x][next_y] = true;
			}
		}
	}

}


int main() {
	int testcase,cnt=0,x,y;
	int earthworm = 0;
	cin >> testcase;
	int *answer = new int[testcase];
	for (int i = 0; i < testcase; i++)
	{
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		earthworm = 0;
		cin >> height >>width>> cnt;
		for (int j = 0; j < cnt; j++)
		{
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int j = 0; j < height; j++)
		{

			for (int k = 0; k < width; k++)
			{
				if (visit[j][k] == false && map[j][k] == 1) {
					bfs(j, k);
					earthworm++;
				}
			}
		}



		cout <<earthworm<<"\n";

	}

	return 0;
}