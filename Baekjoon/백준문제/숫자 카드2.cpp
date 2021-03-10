//10816
// 2021.03.09

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001

using namespace std;

int N, M, max_cnt;
int main() {
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



/*
int bicheck(int start, int end, long long target,int count) {
	if (start > end) return -1;
	int middle = (start + end) / 2;
	if (list[middle] == target) {
		count++;
		max_cnt = max(max_cnt, count);
		bicheck(middle + 1, end, target,count);
		bicheck(start, middle - 1, target, count);
	}
	else if (list[middle] > target)
		bicheck(start, middle - 1, target, count);
	else
		bicheck(middle + 1, end, target, count);


	return max_cnt;

}*/