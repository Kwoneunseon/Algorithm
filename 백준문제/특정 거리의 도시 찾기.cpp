#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool visit[300001] = { false, };
vector<int> map[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K, X, start, destination;
	cin >> N >> M >> K >> X;
	vector<int> answer;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> destination;
		map[start].push_back(destination);
	}
	queue<pair<int, int> >q;

	q.push({ X,0 });
	int point, count;
	while (!q.empty()) {
		point = q.front().first;
		count = q.front().second;
		q.pop();
		if (count > K)
			break;
		else if (count == K)
			answer.push_back(point);
		else {
			for (int i = 0; i < map[point].size(); i++)
			{
				if (!visit[map[point][i]]) {
					q.push({ map[point][i],count + 1 });
					visit[map[point][i]] = true;
				}
			}

		}

	}

	if (answer.size()==0) {
		cout << "-1";
	}
	else {
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << "\n";
		}
	}

	return 0;
}