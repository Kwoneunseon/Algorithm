#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cake_count(vector<int>v, int cnt, int standard) {
	int sum = 0, cake_cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		if (sum >= standard) {
			cake_cnt++;
			sum = 0;
		}
	}
	return cake_cnt > cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, cnt, cake_length;
	cin >> N >> M >> cake_length;
	vector<int> cakes;

	int front = 0, end;

	for (int i = 0; i < M; i++)
	{
		cin >> end;
		cakes.push_back(end - front);
		front = end;
	}
	cakes.push_back(cake_length - front);

	while (N--) {
		cin >> cnt;
		int low = 1, high = cake_length;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (cake_count(cakes, cnt, mid)) low = mid;
			else
				high = mid;
		}
		cout << low <<"\n";
	}
	return 0;
}