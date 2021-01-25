//BFSÀÌ¿ë
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int > >network;
vector<bool>visit;
int num, connect;
int cnt = 0;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int  pNode = q.front();
		q.pop();
		for (int i = 0; i < network[pNode].size(); i++)
		{
			int cNode = network[pNode][i];
			if (!visit[cNode]) {
				q.push(cNode);
				visit[cNode] = true;
				cnt++;
			}
		}
	}
}

int main() {
	cin >> num >> connect;
	network.resize(num + 1);
	visit.resize(num + 1);

	for (int i = 0; i < connect; i++)
	{
		int parent, child;
		cin >> parent >> child;
		network[parent].push_back(child);
		network[child].push_back(parent);
	}
	fill(visit.begin(), visit.end(), false);

	bfs(1);
	cout << cnt;
	return 0;
}