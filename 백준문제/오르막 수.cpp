#include <iostream>
#include <vector>

using namespace std;
int dp[1001][10] = { 0, };
int main() {
	int n, answer = 0;
	cin >> n;
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n ; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = j; k >= 0; k--)
			{
				dp[i][j] = (dp[i][j]+ dp[i - 1][k])%10007;
			}
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		answer += dp[n][i];
	}
	answer = answer % 10007;

	cout << answer;
	return 0;
}