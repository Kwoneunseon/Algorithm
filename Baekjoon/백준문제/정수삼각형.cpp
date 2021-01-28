//1932
//dp ����ؼ� ǯ

/*
1. i == 0 : �ٷ� ���� �ִ� ���� ���� �� �ִ�.
2. i == j : �ٷ� �� ���ʿ� �ִ� ���� ���� �� �ִ�.
3. �� �� : ���� ������ ���ϰ� ū ���� ����.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int triangle[500][500];
int dp[500][500];
int df(int h) {
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < h; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}
	return *max_element(dp[h-1],dp[h-1]+h);
}

int main() {
	int height , temp;
	cin >> height;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> temp;
			triangle[i][j] = temp;
		}
	}

	cout << df(height);

	return 0;
}