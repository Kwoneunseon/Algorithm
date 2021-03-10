//2512 - 2021.03.10

#include <iostream>
#include <algorithm>

using namespace std;
int N;
long long M;
int money[10001] = { 0, };

bool possible(int mid) {
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += min(mid, money[i]);
	}
	if (sum <= M) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
		sum += money[i];
	}
	cin >> M;
	sort(money, money + N);
	if (sum <= M) {
		cout << money[N - 1];
		return 0;
	}
	int low = 1, high = 100000, result = 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (possible(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result;


	return 0;
}