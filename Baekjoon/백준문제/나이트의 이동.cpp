//7562
//bfs »ç¿ë
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 301

using namespace std; 

bool visit[MAX][MAX] = { false, };
long long check[MAX][MAX] = { 0, };
int mx[] = {-2,-1,-2,-1,1,2,1,2};
int my[] = {1,2,-1,-2,2,1,-2,-1};

int bfs(int sx, int sy, int dx, int dy,int len) {
	queue<pair<pair<int, int> ,int> >q;//x,y¿Í cnt
	int x, y, next_x, next_y,cnt;
	q.push(make_pair(make_pair(sx, sy),0));
	visit[sx][sy] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second;
		cnt++;
		if (x == dx && y == dy)
			return cnt;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			next_x = x + mx[i];
			next_y = y + my[i];
			if (next_x >= 0 && next_x < len && next_y >= 0 && next_y < len && !visit[next_x][next_y]) {
				visit[next_x][next_y] = true;
				q.push(make_pair(make_pair(next_x, next_y),cnt));
			}
		}
	}
	return -1;
}

int main() {
	int Testcase, length,start_x,start_y,destination_x,destination_y;
	cin >> Testcase;
	while (Testcase--) {

		cin >> length >> start_x >> start_y >> destination_x >> destination_y;
		memset(check, 0, sizeof(check));
		memset(visit, false, sizeof(visit));
		cout << bfs(start_x, start_y, destination_x, destination_y, length)<<"\n";
	}

	return 0;
}

