#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int start, end;
	vector<pair<int, int>> classes;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		classes.push_back({ start, end });
	}
	sort(classes.begin(), classes.end());
	pq.push(classes[0]);
	for (int i = 1; i < n; i++)
	{
		if (pq.top().second <= classes[i].first) {
			pq.pop();
		}
		pq.push(classes[i]);
	}
	cout << pq.size();
	return 0;
}