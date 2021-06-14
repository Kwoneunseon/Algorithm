#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

int N, C;
long long house[MAX];

bool possible(int dist) {
	int cnt = 1 , prev = house[0];
	for (int i = 1; i < N; i++)
	{
		if (house[i] - prev >= dist) {
			cnt++;
			prev = house[i];
		}
	}
	if (cnt >= C)
		return true;
	return false;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}
	sort(house, house + N);
	int low = 1, high = house[N - 1] - house[0],result = 0;
	while (low < high) {
		int mid = (low + high) / 2;
		if (possible(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << result;
	return 0;
}
