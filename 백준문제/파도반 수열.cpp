//9461
//dp
#include <iostream>
#include <vector>

using namespace std;

long long dp[102];

int main() {
	int n,testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
		for (int i = 6; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[n]<<"\n";
	}


	return 0;
}