#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<vector<int> > v(10001);
bool visit[10001] = { false, };

int dfs(int start) {
	int count = 0;
	queue <int>q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++)
		{
			if (!visit[v[now][i]]) {
				count++;
				q.push(v[now][i]);
				visit[v[now][i]] = true;
			}
		}
	}
	return count;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int>answer;
	int n, m,A,B,max=-1;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> A >> B;
		v[B].push_back(A);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i]) {
			int count = dfs(i);
			if (max < count) {
				max = count;
				answer.clear();
				answer.push_back(i);
			}
			else if(max== count){
				answer.push_back(i);
			}
		}
		memset(visit, false, sizeof(visit));
	}
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}