//11722
//dp»ç¿ë
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int num[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (num[j] > num[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	cout << *max_element(dp, dp + 1000);


	return 0;
}