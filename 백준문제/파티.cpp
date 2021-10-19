#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321
#define MAX 1001 //학생수는 1000이 최대이다.


using namespace std;

vector<pair<int, int>> map[MAX];//학생과 학생 사이의 가중치 입력한 벡터
vector<vector<int>> cost;//i학생기준, 모든 정점에 대해 최단 경로 가중치 입력. 

int N, M;

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
				pq.push({ -next_cost,next });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int X;//파티 장소
	cin >> N >> M >> X;
	//cost를 모든 값이 INF인 (N+1)x(N+1)행렬로 초기화
	cost.resize(N + 1, vector<int>(N+1,INF));

	int first, last, weight;
	for (int i = 0; i < M; i++)
	{
		cin >> first >> last >> weight;
		map[first].push_back({ last,weight });
	}

	for (int i = 1; i <= N; i++)
	{
		dijkstra(i);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, cost[X][i] + cost[i][X]);
	}

	cout << answer;
	
	return 0;
}