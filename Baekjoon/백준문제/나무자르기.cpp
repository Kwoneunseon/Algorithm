//2805번
//다시 풀어 보기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long>trees;
long long N, M, answer=0;

void bisearch(long long start, long long end) {
	if (start > end) return ;
	long long sum = 0;
	long long mid = (start + end) / 2;
	for (int i = 0; i < N; i++)
	{
		if (trees[i] > mid) {
			sum += (trees[i] - mid);
		}
	}

	if (sum >= M) {
		if (answer < mid) answer = mid;
		bisearch(mid + 1, end);
	}
	else
		bisearch(start, mid - 1);
}

int main() {
	long long temp;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		trees.push_back(temp);
	}
	sort(trees.begin(), trees.end());
	bisearch(0, trees[N - 1]);
	cout << answer;
	return 0;
}