#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>v;
	int dp[10001];
	memset(dp, -1, sizeof(int) * 10001);
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (v.end() == find(v.begin(), v.end(), temp)) {
			v.push_back(temp);
			dp[temp] = 1;
		}
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i > v[j] && dp[i-v[j]]!=-1) {
				if (dp[i] != -1)
					dp[i] = min(dp[i - v[j]] + 1, dp[i]);
				else
					dp[i] = dp[i - v[j]] + 1;
			}
		}

	}
	cout << dp[k];
	return 0;
}