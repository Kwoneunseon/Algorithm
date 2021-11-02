#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//문자열은 최대 1000자이기 때문
int dp[1002][1002] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= b.length(); i++)
	{
		for (int j = 1; j <= a.length(); j++)
		{
			if (b[i - 1] == a[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[b.length()][a.length()];

	return 0;
}