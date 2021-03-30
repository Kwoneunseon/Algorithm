#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > relation(101);
bool visit[101] = { false, };

int bfs(int x, int y) {

	queue<pair<pair<int, int>,bool*> > q;//q:
	q.push({ { x,0 },visit });
	while (!q.empty()) {
		int a = q.front().first.first;
		int count = q.front().first.second;
		visit[a] = true;
		q.pop();
		if (a == y)
			return count;
		for (int i = 0; i < relation[a].size(); i++)
		{
			if (relation[a][i] != a &&!visit[relation[a][i]]) {
				q.push({ { relation[a][i], count + 1 },visit });
			}
		}

	}
	return -1;

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

	cout<<bfs(x, y);


	return  0;
}