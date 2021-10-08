#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 20010
#define INF 987654321
using namespace std; 

int V, E, start;


vector<pair<int, int> > node[MAX];
int dist[MAX];


void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	
	while (!pq.empty()) {
		int Cost = -pq.top().first;
		int Current = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[Current].size(); i++)
		{
			int Next = node[Current][i].first;
			int Next_dist = Cost + node[Current][i].second;

			if (dist[Next] > Next_dist) {
				dist[Next] = Next_dist;
				pq.push({ -dist[Next],Next });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E >> start;
	
	fill(dist,dist+V+2,INF);
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back({v,w });
		dist[i + 1] = INF;
	}

	dijkstra(start);


	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	

	return 0;
}