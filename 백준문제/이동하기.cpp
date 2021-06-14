//½ÇÆÐ

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int> > miro;
bool visit[1001][1001] = { false };
int n, m;
int island_cnt;
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int na = a + dx[i];
			int nb = b + dy[i];
			if (na < n && nb < m && visit[na][nb] == false) {
				island_cnt += miro[na][nb];
				q.push(make_pair(na, nb));
				visit[na][nb] = true;
			}

		}
	}



}

int main() {
	int temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			line.push_back(temp);
		}
		miro.push_back(line);
	}

	bfs(0, 0);

	cout << island_cnt;
	return 0;
}