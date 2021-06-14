//10816
// 2021.03.09

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001

using namespace std;

int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<long long>list(N);
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	cin >> M;
	sort(list.begin(), list.end());
	int low, upper;
	for (int i = 0; i < M; i++)
	{
		long long temp;
		cin >> temp;
		low = lower_bound(list.begin(), list.end(), temp)-list.begin();
		upper = upper_bound(list.begin(), list.end(), temp) - list.begin();
		cout << upper - low<<" ";
	}

	return 0;
}

