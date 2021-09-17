#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int> > map;
bool visit_edge[101][101] = { false, };
int n, m;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int a,int b) {
	int answer = 0;
	int x, y, new_x, new_y;
	queue<pair<pair<int, int> ,int>>q;
	q.push(make_pair(make_pair(a, b), 1));
	visit_edge[a][b] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		answer = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			return answer;
		}
		for (int i = 0; i < 4; i++)
		{
			new_x = x + dx[i];
			new_y = y + dy[i];
			if (new_x >= 0 && new_y >= 0 && new_x < n &&new_y < m && !visit_edge[new_x][new_y]) {
				if (map[new_x][new_y] == 1) {
					q.push(make_pair(make_pair(new_x, new_y), answer + 1));
					visit_edge[new_x][new_y] = true;
				}
			}

		}

	}


	return -1;
}


int main() {
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n; i++)
	{
		vector<int >v;
		cin >> temp;
		for (int j= 0; j < m; j++)
		{
			v.push_back(temp[j]-'0');
		}
		map.push_back(v);
	}
	cout << bfs(0, 0);
	


	return 0;
}