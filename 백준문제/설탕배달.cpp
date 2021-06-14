#include <iostream>
#include <algorithm>

using namespace std;

int dp[5001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		dp[i] = 10000;
	}
	dp[3] = 1, dp[5] = 1;
	for (int i = 6; i <= n; i++)
	{
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	if (dp[n]<10000)
		cout << dp[n];
	else 
		cout << -1;
	return 0;
}