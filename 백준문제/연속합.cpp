//1912
//dp���
/*��Ʈ : 
	�ڽ��� �ε��� dp����
	���ݱ��� ���Ѽ� + �ڽ��� ��, �ڽ��� �� �� ū ���� ����.
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