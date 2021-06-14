//1654 - 2021.03.08
//솔루션 보고 해결(https://yongmemo.tistory.com/21) - 2021.03.09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K;
long long N,answer=0;
long long list[10001] = { 0, };

long long bicheck(long long start, long long end) {
	while (start <= end) {
		long long cnt = 0;
		long long middle = (start + end) / 2;
		for (int i = 0; i <= K; i++)
		{
			cnt += list[i] / middle;
		}
		if (cnt >= N) {
			start = middle + 1;
			answer = max(answer, middle);
		}
		else end = middle - 1;
	}
	return answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> N;
	long long maxi;
	for (int i = 0; i < K; i++)
	{
		cin >> list[i];
		maxi = max(maxi, list[i]);
	}
	cout << bicheck(1, maxi);

	return 0;
}