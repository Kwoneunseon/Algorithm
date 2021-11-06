#include <iostream>
#include <vector>

using namespace std;

vector<int> number;
long long *sum_dp;

int init(int start, int end, int node) {
	if (start == end) return sum_dp[node] = number[start];
	int mid = (start + end) / 2;

	return sum_dp[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return sum_dp[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif) {
	if (index < start || index > end) return;

	sum_dp[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num_size, M, K;

	cin >> num_size >> M >> K;

	sum_dp = new long long[4*num_size];
	
	for (int i = 1; i <= num_size; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}

	init(0, num_size-1, 1);


	int cmd , first,second;
	for (int i = 0; i < M+K; i++)
	{
		cin >> cmd >> first >> second;
		//first번째 수를 second로 바꾼다
		if (cmd == 1) {
			second = second - number[first - 1];
			update(0, num_size - 1, 1, first-1, second);
		}
		//first-second번째수까지의 합 구하기
		else if (cmd == 2) {
			cout << sum(0, num_size, 1, first-1, second)<<"\n";
		}
	}


	return 0;
}