#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, K, X,start,destination;
	cin >> N >> M >> K >> X;
	vector<vector<int> >map(N + 1);
	vector<int> answer;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> destination;
		map[start].push_back(destination);
	}
	int *check = new int[N + 2];
	queue<pair<int, int> > q;
	q.push({ X,0 });
	int point, cnt;
	while (!q.empty()) {
		point = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (check[point] < 0) {
			check[point] = cnt;
			if (cnt == K)
				answer.push_back(point);
		}

		for (int i = 0; i < map[point].size(); i++)
		{
			q.push({ map[point][i],cnt + 1 });
		}
	}
	if (answer.size() == 0)
		cout << "-1";
	else {
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << "\n";
		}
	}

	return 0;
}