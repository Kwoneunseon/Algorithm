//1753
//bfs
//ㅠㅠㅠ어려워
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,int> > edges[20001]; //다음 정점과 가중치
bool visit[20001];
int min_weight = 3000000;

int bfs(int start, int destination, int total_w) {
	if (start == destination)
		return total_w;
	bool flag = false;
	for (int i = 0; i < edges[start].size(); i++)
	{
		if (visit[edges[start][i].first] == false)
			flag= true;
	}
	if (!flag)
		return -1;
	queue<int>q;
	q.push(start);
	while (!q.empty()) {
		int x, next_x;
		x = q.front();
		q.pop();
		for (int i = 0; i < edges[x].size(); i++)
		{
			next_x = edges[x][i].first;
			min_weight = min(min_weight,bfs(next_x, destination, total_w + edges[x][i].second));
		}
	}
	return min_weight;
}


int main() {
	int vertex, edge, start_point;
	cin >> vertex>> edge >> start_point;
	for (int i = 0; i < edge; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(v,w));
	}
	int total_weight = 0;
	for (int i = 1; i <= vertex; i++)
	{
		total_weight = 0;
		total_weight = bfs(start_point, i, total_weight);
		cout << total_weight;
	}



	return 0;
}