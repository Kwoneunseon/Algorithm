//14501
//dp사용
//너무 어렵다,,
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	int n,time, pay;
	cin >> n;
	//다이나믹 프로그래밍을 사용하기 위해
	int dp[17] = { 0, };
	int T[16] = { 0, };
	int P[16] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		cin >> T[i] >> P[i];
		dp[i] = P[i];
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i ; j++) // j일까지의 이익
		{
			if (i - j > T[j]) {
				dp[i] = max(P[i] + dp[j], dp[i]);
			}
		}
	}
	int max = 0;

	for (int i = 1; i <= n; i++) {
		if (i + T[i] <= n + 1) {
			if (max < dp[i]) {
				max = dp[i];
			}
		}
	}
	cout << max;
	return 0;
}