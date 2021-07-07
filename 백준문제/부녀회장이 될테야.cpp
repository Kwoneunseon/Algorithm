#include <vector>
#include <iostream>

using namespace std;

int main() {
	int T, k, n;
	cin >> T;
	while (T--) {
		cin >> k >> n;//kÃş nÈ£;
		vector<int> temp(n+2),dp(n+2);
		for (int i = 0; i <= n; i++)
		{
			dp[i] = i;
		}
		
		while (k--) {
			for (int i = 1; i <= n; i++)
			{
				dp[i] = dp[i] + dp[i - 1];
			}
		}
		cout << dp[n];
	}


	return 0;
}