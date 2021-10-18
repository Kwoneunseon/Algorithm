#include <iostream>
#include <vector>
#include <queue>	
#include <algorithm>

#define INF 987654321

using namespace std;
int n, m, x;
vector<pair<int,int>> map[1001];

int dijkstra(int start) {
	int *cost = new int[n + 1];
	fill(cost, cost + n + 1, INF);
	cost[start] = 0;

	priority_queue<pair<int, int>>pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int n_cost = -pq.top().first;
		int current = pq.top().second;	
		pq.pop();

		if(cost[current] < n_cost) continue;
		for (int i = 0; i < map[current].size(); i++)
		{
			int next = map[current][i].first;
			int next_cost = n_cost + map[current][i].second;
			if (cost[next] > next_cost) {
				cost[next] = next_cost;
				pq.push({ -next_cost, next });
			}
		}
	}
	return cost[x];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> x;

	int start, def, weight;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> def >> weight;
		map[start].push_back({ def,weight });
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, dijkstra(i));
	}
	cout << answer;
	return 0;
}