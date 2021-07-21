#include <iostream>

using namespace std;

int main() {
	//에레토스테네스의 체 사용
	int M, N, min=10001, sum = 0;
	cin >> M >> N;
	int *prime = new int[N + 1];
	for (int i = 1; i <= N; i++)
	{
		prime[i] = i;
	}
	//1을 제외
	prime[1] = 0;
	for (int i = 2 ;i <= N; i++)
	{
		if (prime[i] == 0)
			continue;
		for (int j = i*i; j  <= N; j+=i )
		{
			prime[j] = 0;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (prime[i] != 0) {
			sum += prime[i];
			if (prime[i] < min)
				min = prime[i];
		}
	}
	if (sum == 0)
		cout << -1;
	else
		cout << sum << "\n" << min;
	return 0;
}