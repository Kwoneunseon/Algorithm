#include <iostream>
using namespace std;
int finish[10000] = { 0, }, visit[10000] = { 0, };
int graph[10000] = { 0, },cnt=0;
void dfs(int node) {
	visit[node] = 1;
	int nextNode = graph[node];
	if (visit[nextNode] == 0) {
		dfs(nextNode);
	}
	else if (finish[nextNode] == 0) {
		while (nextNode != node) {
			cnt++;
			nextNode = graph[nextNode];
		}
		cnt++;
	}
	finish[node] = 1;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i <= 10000; i++)
		{
			visit[i] = 0;
			graph[i] = 0;
			finish[i] = 0;
		}
		cnt = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int temp;
			cin >> temp;
			graph[i] = temp;
		}
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0) {
				dfs(i);
			}
		}
		cout << n - cnt<<"\n";
	}
	return 0;
}