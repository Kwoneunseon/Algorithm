#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	vector<long long> dp(10001);
	cin >> n >> m;
	//m���� ���� ���� ��� A�� ���ֱ⿡ 1
	fill(dp.begin(),dp.begin()+m, 1);
	dp[m] = 2; //��� B�� ���, ��� A�� ���
	for (int i = m+1; i <= n; i++)
	{
		dp[i] = (dp[i - m] + dp[i - 1])%1000000007;
	}
	cout << dp[n];

	return 0;

}