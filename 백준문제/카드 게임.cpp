#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1000][1000][2];
int card[1000];
//flag를 통해서 근우차례와 명우차례 구분
int solve(int start, int end, bool flag) {
	int &ret = dp[start][end][flag];
	if (ret != -1) return ret;
	if (start == end) {
		if (flag)
			return ret = card[start];
		else
			return ret = 0;
	}
	if (flag)
		return ret = max(solve(start + 1, end, false) + card[start], solve(start, end - 1, false) + card[end]);
	else
		return ret = min(solve(start + 1, end, true), solve(start, end - 1, true));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			cin >> card[i];
		}
		cout << solve(0, n - 1, true) << "\n";

	}


	return 0;
}