#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 3;
	
	while (t--) {
		int n, coin, cnt,sum=0;
		int dp[100001] = { 0, };
		cin >> n;
		vector<pair<int, int> >money;
		for (int i = 0; i < n; i++)
		{
			cin >> coin >> cnt;
			sum += coin * cnt;
			money.push_back({ coin,cnt });
		}
		if (sum % 2 != 0) {
			cout << "0\n";
			continue;
		}
		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = sum/2; j >= money[i].first; j--)
			{
				if (dp[j - money[i].first] == 1) {
					for (int k = 0;  k < money[i].second;  k++)
					{
						if (j + k * money[i].first > sum / 2)break;
						else dp[j + k * money[i].first] = 1;
					}
				}
			}

		}

		if (dp[sum / 2] == 1)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";

	}

	return 0;
}