//2021.03.13 - dp
//2294

#include <iostream>	
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	int n, k;
	int coins[101];
	int dp[10001];
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		dp[i] = 100000;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> coins[i];
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
	if (dp[k] == 100000)
		cout << -1;
	else cout << dp[k];


	return 0;
}