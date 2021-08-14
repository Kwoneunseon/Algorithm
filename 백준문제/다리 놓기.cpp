#include <iostream>

using namespace std;
int n, m;
int dp[31][31] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= 30; i++)
	{
		dp[1][i] = i;
	}
	while (T--) {
		cin >> n >> m;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 2; j <= m; j++)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			}
		}
		cout << dp[n][m] << "\n";
	}



	return 0;
}