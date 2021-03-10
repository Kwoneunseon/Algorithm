//1789 => 2021.03.10
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 4294967295

using namespace std;

long long check(int mid) {
	long long sum = 0;
	for (int i = 1; i <= mid; i++)
	{
		sum += i;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int S, N,answer = 0;
	cin >> S;
	int low = 1, high = sqrt(MAX);
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid) <= S) {
			answer = max(answer, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}
	cout << answer;


	return 0;
}