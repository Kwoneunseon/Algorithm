//12865
//dp - knapsack
#include <iostream>
#include <algorithm>

using namespace std;

int items[101][2];
int dp[100][100001] = { 0, };

int main() {
	int n, k, w, v;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;
		items[i][0] = w; 
		items[i][1] = v;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= items[i][0]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i][0]] + items[i][1]);
			}
			else
				dp[i][j] = dp[i][j - 1];
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