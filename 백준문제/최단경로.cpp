#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 20002 //V의 크기가 20000이하
#define INF 987654321
using namespace std;

int V, E, start;

vector<pair<int, int> >node[MAX];
int dist[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0,start));//(cost, 현재노드)
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		//cost에 -해주는 이유 : 짧은 cost를 먼저 처리하기 위해서
		int current = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[current].size(); i++)
		{
			int next = node[current][i].first;
			int next_cost = cost + node[current][i].second;

			//다음 노드를 사용해서 가는 거리가 지금까지 간 거리보다 짧은 경우.
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}

	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v,w));
	}
	//dist초기화
	fill(dist, dist + V + 2, INF);
	//다익스트라 알고리즘
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