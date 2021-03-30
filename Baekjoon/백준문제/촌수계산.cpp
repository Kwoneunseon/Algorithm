#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<vector<int> > relation(101);
int visit[101] = { -1, };

int bfs(int x, int y) {
	queue<int>q;
	q.push(x);
	visit[x] = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 0; i < relation[a].size() ; i++)
		{
			if (visit[relation[a][i]]==-1)
				q.push(relation[a][i]), visit[relation[a][i]] = visit[a]+ 1;
		}
	}
	return visit[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;//사람의 수 : n, 관계의 개수 : m
	int x, y, temp_x,temp_y;
	cin >> n >> x >> y;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp_x >> temp_y;
		relation[temp_x].push_back(temp_y);
		relation[temp_y].push_back(temp_x);
	}
	memset(visit, -1, sizeof(visit));
	cout<<bfs(x, y);


	return  0;
}