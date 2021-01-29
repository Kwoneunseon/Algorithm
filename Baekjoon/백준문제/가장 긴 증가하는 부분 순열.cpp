//11053
//dp사용
/*
	dp[i] = max(dp[j]+1,dp[i]);
	이부분 잘 기억해.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int num[1000];
int dp[1000];

int main() {

	int n, temp, answer = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		num[i] = temp;
	}
	
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (num[j] < num[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	cout <<*max_element(dp,dp+1000);

	return 0;
}

/*
9
10 20 15 20 30 60 20 40 50
*/
