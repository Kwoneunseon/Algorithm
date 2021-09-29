#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
long long dp[1001][3][3][2];//현재위치, 현재 높이, 과거 높이, 2이상 장애물
long long mod = 1000000007;

long long solve(int now, int state, int laststate, bool flag) {
	
	long long &ref = dp[now][state][laststate][flag];

	if (now == n - 1) {
		if (flag)
			return ref = 1;
		else
			return ref;
	}

	if (ref != 0)
		return ref;

	if (state == 0) {
		ref += solve(now + 1, 0, state, flag) % mod;
		ref += solve(now + 1, 1, state, flag) % mod;
		ref += solve(now + 1, 2, state, true) % mod;
	}
	else if (state == 1) {
		if (laststate == 0) {
			ref += solve(now + 1, 0, state, flag) % mod;
			ref += solve(now + 1, 1, state, flag) % mod;
			ref += solve(now + 1, 2, state, true) % mod;
		}
		else {
			ref += solve(now + 1, 0, state, flag) % mod;
		}
	}
	else if (state == 2) {
		if (laststate == 0) {
			ref += solve(now + 1, 0, state, flag) % mod;
			ref += solve(now + 1, 1, state, flag) % mod;
		}
		else {
			ref += solve(now + 1, 0, state, flag) % mod;
		}
	}
	return ref %= mod;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cout << solve(0, 0, 0, false);

	return 0;
}