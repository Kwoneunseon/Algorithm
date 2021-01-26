//7576
//bfs 이용함.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> net[101];
bool visit[101] = { false, };
int infection = -1;

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		infection++;
		visit[temp] = true;
		for (int i = 0; i < net[temp].size(); i++)
		{
			if (visit[net[temp][i]] == false) {
				q.push(net[temp][i]);
				visit[net[temp][i]] = true;
			}
		}
	}
}

int main() {
	int computers,net_cnt;
	cin >> computers >> net_cnt;
	int a, b;
	for (int i = 0; i < net_cnt; i++)
	{
		cin >> a >> b;
		net[a].push_back(b);
		net[b].push_back(a);
	}

	bfs(1);
	cout << infection;


	return 0;
}