//10816
// 2021.03.09

#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;

int N, M;
long long list[MAX] = { 0, };

int bicheck(int start, int end, long long target) {
	int cnt = 0;
	while (start <= end) {
		int middle = (start + end) / 2;
		if (list[middle] == target)
			cnt++;
		if (list[middle] >= target)
			end = middle - 1;
		else
			start = middle + 1;
	}

	return cnt;

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	cin >> M;
	sort(list, list + N);
	for (int i = 0; i < M; i++)
	{
		long long temp;
		cin >> temp;
		cout << bicheck(0, list[N - 1], temp)<<" ";
	}

	return 0;
}
