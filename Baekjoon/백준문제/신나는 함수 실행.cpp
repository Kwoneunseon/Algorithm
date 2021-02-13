//9184
//dp
#include <iostream>
#define MAX 51
using namespace std;

long long dp[MAX][MAX][MAX] = { 0, };

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		if (dp[20][20][20] != 0) {
			dp[a][b][c] = dp[20][20][20];
		}
		return w(20, 20, 20);
	}
	else if (a < b&&b < c) {
		if (dp[a][b][c - 1] == 0)
			dp[a][b][c - 1] = w(a, b, c - 1);
		if (dp[a][b - 1][c - 1] == 0)
			dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		if (dp[a][b - 1][c] == 0)
			dp[a][b - 1][c] = w(a, b - 1, c);
		dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];

		return dp[a][b][c];
	}
	else {
		if (dp[a-1][b][c] == 0)
			dp[a-1][b][c] = w(a-1, b, c);
		if (dp[a-1][b - 1][c] == 0)
			dp[a-1][b - 1][c] = w(a-1, b - 1, c);
		if (dp[a-1][b ][c-1] == 0)
			dp[a-1][b][c-1] = w(a-1, b, c-1);
		if (dp[a - 1][b - 1][c - 1] == 0)
			dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
		dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
		return dp[a][b][c];
	}
}



int main() {
	int a, b, c, answer;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c<<") = " << w(a, b, c)<<"\n";
	}



	return 0;
}