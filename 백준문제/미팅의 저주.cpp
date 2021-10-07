#include <iostream>
using namespace std;

int main() {
	long long n;
	long long dp[5001] = { 1 };
	cin >> n;
	
	for (long i = 1; i <=  n/2; i++)
	{
		for (long j = 0; j < i; j++)
		{
			dp[i] += (dp[j] * dp[i - 1 - j]) % 987654321;
		}
	}

	cout << dp[n / 2]%987654321<<"\n";

	return 0;
}