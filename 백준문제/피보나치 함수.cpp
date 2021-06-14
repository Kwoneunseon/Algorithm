//1003
//dp

#include <iostream>
#include <vector>
using namespace std;

pair<int, int>dp[40];

pair<int, int> fibo(int N) {
	if (N == 0)
		return dp[0];
	else if (N == 1)
		return dp[1];

	if (dp[N].first != 0 && dp[N].second != 0) {
		return dp[N];
	}
	return dp[N] = make_pair(fibo(N - 1).first + fibo(N - 2).first, fibo(N - 1).second + fibo(N - 2).second);
}

int main() {
	int T,N;
	cin >> T;
	dp[0].first = 1;
	dp[0].second = 0;
	dp[1].second = 0;
	dp[1].second = 1;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << fibo(N).first << " " << fibo(N).second<<"\n";
	}
	return 0;
}