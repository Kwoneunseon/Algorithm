#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int vertex, edge;
vector<int>connect[1001];
bool visit[1001];

void bfs(int start) {
	queue<int>q;
	q.push(start);
	int temp;
	visit[start] = true;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (int i = 0; i < connect[temp].size(); i++)
		{
			if (visit[connect[temp][i]] == false) {
				visit[connect[temp][i]] = true;
				q.push(connect[temp][i]);
			}
		}
	}
}

int main() {
	cin >> vertex >> edge;
	int temp, x,y,count=0;
	for (int i = 0; i < edge; i++)
	{
		cin >> x >> y;
		connect[x].push_back(y);
		connect[y].push_back(x);
	}
	for (int i = 1; i <=vertex; i++)
	{
		if (visit[i] == false) {
			bfs(i);
			count++;
		}
	}

	cout << count;

	

	return 0;
}