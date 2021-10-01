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
	//m보다 작은 수는 모두 A만 써있기에 1
	fill(dp.begin(),dp.begin()+m, 1);
	dp[m] = 2; //모두 B일 경우, 모두 A일 경우
	for (int i = m+1; i <= n; i++)
	{
		dp[i] = (dp[i - m] + dp[i - 1])%1000000007;
	}
	cout << dp[n];

	return 0;

}