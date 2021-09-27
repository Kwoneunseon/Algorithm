#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

class Node {
public:
	int dist;
	int next;
};

bool operator> (Node a, Node b) {
	return a.dist > b.dist;
}

vector<Node>map[10001];
int dist_ji[101];
int dist_seong[101];

void Dijkstra(int dist[],int start) {
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ 0,start });
	fill(dist, dist + 101, 100001);
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_dist = pq.top().dist;
		int cur = pq.top().next;
		pq.pop();

		if (dist[cur] < cur_dist) continue;
		for (int i = 0; i < map[cur].size(); i++)
		{
			int next_dist = map[cur][i].dist;
			int next = map[cur][i].next;

			if (dist[next] > cur_dist + next_dist) {
				Node temp;
				temp.next = next;
				dist[next] = cur_dist + next_dist;
				temp.dist = dist[next];
				pq.push(temp);
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, m,a,b,c,ji,seong;
	cin >> v >> m;

	while (m--) {
		cin >> a >> b >> c;
		map[a].push_back({c,b });
		map[b].push_back({c,a });
	}

	cin >> ji >> seong;
	Dijkstra(dist_ji, ji);
	Dijkstra(dist_seong, seong);
	
	int min_dist = 100001;

	for (int i = 1; i <= v; i++)
	{
		if (i != ji && i != seong) {
			min_dist = min(min_dist, dist_ji[i] + dist_seong[i]);
		}
	}
	vector<pair<int,int>>answer;
	for (int i = 1; i <= v; i++)
	{
		if (i != ji && i != seong) {
			if (dist_ji[i] <= dist_seong[i] && dist_ji[i] + dist_seong[i] == min_dist)
				answer.push_back({ dist_ji[i],i });
		}
	}

	sort(answer.begin(), answer.end());
	if (answer.empty())
		cout << -1;
	else
		cout << answer[0].second;

	return 0;
}