//1912
//dp사용
/*힌트 : 
	자신의 인덱스 dp에는
	지금까지 구한수 + 자신의 값, 자신의 값 중 큰 값이 들어간다.
*/
#include <iostream>	
#include <algorithm>
using namespace std;

int main() {

	int n,temp, answer=-1000;
	cin >> n;
	int *dp = new int[n+1];
	int *num = new int[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		num[i] = temp;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		if (answer < dp[i])
			answer = dp[i];

	}

	cout << answer;


	return 0;
}