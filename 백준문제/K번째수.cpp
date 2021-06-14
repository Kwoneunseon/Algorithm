#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long n, k;

long long count(long long mid) {
	long long sum = 0;
	for (long long i = 1; i <= n; i++)
	{
		sum += min(n, mid / i);
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> k;
	long long first, end;
	first = 1, end = n * n;
	while (first <= end) {
		long long mid = (first + end) / 2;
		if (count(mid) < k)
			first = mid+1;
		else {
			end = mid - 1;
		}
	}

	cout << first;

	return 0;
}