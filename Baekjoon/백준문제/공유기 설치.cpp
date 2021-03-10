//2021.03.10
// https://jaimemin.tistory.com/966  Âü°í
#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;

int N, C;
long long homes[MAX];

bool possible(int dist){
	int cnt = 1;
	int prev = homes[0];
	for (int i = 1; i < N; i++)
	{
		if (homes[i] - prev >= dist) {
			cnt++;
			prev = homes[i];
		}
	}
	if (cnt >= C)return true;
	return false;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> homes[i];
	}
	sort(homes,homes+N);

	int low = 1, high = homes[N - 1] - homes[0];
	int result = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (possible(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result << "\n";
	return 0;
}