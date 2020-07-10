#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int>arr[1001];
int c[1001] = { 0, };


void bfs(int start) {
	
	queue<int> q;
	q.push(start);
	c[start] = 1;
	while (!q.empty()) {
		int key = q.front();
		q.pop();
		cout << key << " ";
		sort(arr[start].begin(), arr[start].end());
		for (int i = 0; i < arr[key].size(); i++)
		{
			int y = arr[key][i];
			if (c[y] != true) {
				c[y] = true;
				q.push(y);
			}
		}
	}
}

void dfs(int start) {
	cout << start << " ";
	c[start] = 1;
	sort(arr[start].begin(), arr[start].end());
	for (int i = 0; i < arr[start].size(); i++)
	{
		int y = arr[start][i];
		if (c[y] != true) {
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, start;// n : 정점의 개수, m 간선의 개수;
	cin >> n >> m >> start;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	dfs(start);
	memset(c, 0, sizeof(c));
	cout << "\n";
	bfs(start);



	return 0;
}