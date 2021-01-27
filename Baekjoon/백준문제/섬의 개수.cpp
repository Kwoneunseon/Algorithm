#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visit[51][51] = { false, };
int island_cnt;

int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,-1,1 };

void bfs(int a, int b, int h, int w, vector<vector<int> >m) {
	int x, y, next_x, next_y;
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x < h && next_x >= 0 && next_y < w&& next_y >= 0 && !visit[next_x][next_y]) {
				if (m[next_x][next_y] == 1) {
					q.push(make_pair(next_x, next_y));
				}
				visit[next_x][next_y] = true;
			}
		}
	}


}


int main() {
	int width, height, temp;
	while (true) {
		vector<vector<int> > map;
		cin >> width >> height;
		if (width == 0 && height == 0)
			break;
		memset(visit, false, sizeof(visit));
		island_cnt = 0;
		//입력
		for (int i = 0; i < height; i++)
		{
			vector<int> w;
			for (int j = 0; j < width; j++)
			{
				cin >> temp;
				w.push_back(temp);
			}
			map.push_back(w);
		}
		//섬 개수 확인
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (visit[i][j] == false && map[i][j] == 1) {
					bfs(i, j, height, width, map);
					island_cnt++;
				}
			}
		}

		cout << island_cnt << "\n";

	}


	return 0;
}