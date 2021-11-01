#include <iostream>

using namespace std;

int money[101], dp[10001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> money[i];
	}
	//µ¿
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = money[i]; j <= k; j++)
		{
			dp[j] += dp[j - money[i]];
		}
	}

	cout << dp[k];

	return 0;
}