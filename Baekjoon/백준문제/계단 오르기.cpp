//2579
//dp 사용
#include <iostream>
#include <algorithm>

using namespace std;

int stair[300];
int dp[300];


int main() {
	int n,temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		stair[i] = temp;
	}

	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	for (int i = 2; i < n; i++)
	{
		//두 계단을 오르는 경우 // 한 계단씩 오르는 경우
		dp[i] =max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << dp[n - 1];
	return 0;
}