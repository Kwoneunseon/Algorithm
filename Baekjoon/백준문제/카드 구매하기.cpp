//11052
//dp
#include <iostream>
#include <algorithm>
using namespace std;

int card[1001], dp[1001] = { 0, };

int cal(int num) {
	int max_value = 0;
	if (dp[num] != 0)
		return dp[num];
	for (int i = 1; i < num; i++)
	{
		max_value = max(cal(i) + cal(num - i), max_value);
	}
	dp[num] = max(max_value, card[num]);
	return dp[num];
}

int main() {
	int cnt, temp;
	cin >> cnt;

	for (int i = 1; i <= cnt; i++)
	{
		cin >> temp;
		card[i] = temp;
	}
	dp[1] = card[1];
	cout << cal(cnt);
	return 0;
}