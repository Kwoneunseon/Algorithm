//9095
//dp 이용
//솔루션 보고 해결.
#include <iostream>
using namespace std;

int main() {
	int T , num;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int dp[12];
		dp[1] = 1, dp[2] = 2, dp[3] = 4;
		cin >> num;
		for (int i = 4; i <= num; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[num] << "\n";

	}
	return 0;
}