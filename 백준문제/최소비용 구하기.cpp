#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 1001
#define INF 987654321

using namespace std;

int N, M, start, destination;

vector<pair<int, int> > bus[MAX];
int cost[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int> >pq;
	pq.push({ 0,start });
	cost[start] = 0;

	while (!pq.empty()) {
		int n_cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		//이 조건 없을 때 시간초과 오류 발생함.
		if (cost[current] < n_cost) continue;
		for (int i = 0; i < bus[current].size(); i++)
		{
			int next = bus[current][i].first;
			int next_cost = n_cost + bus[current][i].second;
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

	cin >> N >> M;
	fill(cost, cost + N + 1, INF);
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		bus[u].push_back({ v,w });
	}
	cin >> start >> destination;
	dijkstra(start);
	cout << cost[destination];


	return 0;
}