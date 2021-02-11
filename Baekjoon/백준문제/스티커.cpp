//9465
//dp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long dp[2][100001];
long long buf[2][100001];

int main() {
	int Testcase,col,temp;
	cin >> Testcase;
	while (Testcase--) {
		cin >> col;

		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> temp;
				buf[i][j] = temp;
			}
		}

		
		dp[0][0] = buf[0][0];
		dp[1][0] = buf[1][0];
		dp[0][1] = buf[1][0] + buf[0][1];
		dp[1][1] = buf[0][0] + buf[1][1];

		for (int i = 2 ; i < col; i++)
		{
			dp[0][i] = buf[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = buf[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		cout << max(dp[0][col - 1], dp[1][col - 1]) << "\n";

	}


	return 0;
}