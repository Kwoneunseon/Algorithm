#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 801
#define INF 999999999
using namespace std;


vector<pair<int, int>> map[MAX];
vector<vector<int> > cost;


void dijkstra(int start) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });
	cost[start][start] = 0;
	while (!pq.empty()) {
		int current_cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (cost[start][current] < current_cost) continue;
		for (int i = 0; i < map[current].size(); i++)
		{
			int next_cost = current_cost + map[current][i].second;
			int next = map[current][i].first;
			if (cost[start][next] > next_cost) {
				cost[start][next] = next_cost;
				pq.push({ -next_cost, next });
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, E, v1, v2;
	cin >> N >> E;
	cost.resize(N + 1, vector<int>(N + 1, INF));

	int first, last, weight;

	for (int i = 0; i < E; i++)
	{
		cin >> first >> last >> weight;
		map[first].push_back({ last,weight });
		map[last].push_back({ first,weight });
	}
	cin >> v1 >> v2;
	for (int i = 1; i <= N; i++)
	{
		dijkstra(i);
	}
	//v1-v2 사이의 거리를 구한다.
	long long answer = cost[v1][v2];
	if (answer == INF) {
		//v1-v2가 연결되어 있지 않을 경우
	}
	else if (v1 == 1)//v1이 1인 경우 v2-n의 최단경로만 구해준다.
		answer += cost[v2][N];
	else if (v2 == N) {//v2가 n인 경우, 1-v1의 최단경로만 구해준다.
		answer += cost[1][v1];
	}
	else //1-v1-v2-n VS 1-v2-v1-n 중 더 가까운 최단경로를 구한다.
		answer += min(cost[1][v1] + cost[v2][N], cost[1][v2] + cost[v1][N]);
	
	if (answer >= INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}