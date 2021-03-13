//12865
//dp - knapsack
//º¹½À - 2021.03.13
//2021.03.13
//12865
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	int items[101][2];
	int dp[101][100001] = { 0, };
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> items[i][0] >> items[i][1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=  k; j++)
		{
			if (j > items[i][0]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i][0]] + items[i][1]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k];


	return 0;
}

/*
 4 6
 2 2
 1 3
 2 1
 3 2

*/