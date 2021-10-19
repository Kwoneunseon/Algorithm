#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 20002
using namespace std;


vector<pair<int, int> > map[MAX];
vector<int>cost;
int V, E, start;

void dijkstra() {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0, start });
	cost[start] = 0;
	while (!pq.empty()) {
		int current_cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		//이미 최단경로인 경우 시간을 줄이기 위해
		if (cost[current] < current_cost) continue;
		for (int i = 0; i < map[current].size(); i++)
		{
			int next_cost = current_cost + map[current][i].second;
			int next = map[current][i].first;

			if (cost[next] > next_cost) {
				cost[next] = next_cost;
				pq.push({ -next_cost, next });
			}

		}
			  
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start;
	cost.resize(V + 1);
	fill(cost.begin(), cost.end(), INF);
	int first, last, weight;
	for (int i = 0; i < E; i++)
	{
		cin >> first >> last >> weight;
		map[first].push_back({ last,weight });
	}

	dijkstra();

	for (int i = 1; i <= V; i++)
	{
		if (cost[i] == INF)
			cout << "INF\n";
		else
			cout << cost[i] << "\n";
	}


	return 0;
}