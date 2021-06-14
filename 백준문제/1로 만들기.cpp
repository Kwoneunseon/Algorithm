//1463
//dp·Î Ç¯.

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int dp(int N) {
	arr[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = min(arr[i / 2] + 1,arr[i]);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	return arr[N];
}

int main() {

	int N;
	cin >> N;
	cout << dp(N);

	return 0;
}
