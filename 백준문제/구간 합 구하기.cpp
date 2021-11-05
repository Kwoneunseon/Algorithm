#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num_size, M, K;

	cin >> num_size >> M >> K;

	vector<int> number;
	long long *sum_dp = new long long[num_size+2];
	int *dif = new int[num_size + 2];
	fill(dif, dif + num_size + 2, 0);
	fill(sum_dp, sum_dp + num_size + 2, 0);

	number.push_back(0);
	for (int i = 1; i <= num_size; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);

		if (i == 1)
			sum_dp[i] = temp;
		else
			sum_dp[i] = sum_dp[i - 1] + temp;
	}
	int cmd , first,second;
	for (int i = 0; i < M+K; i++)
	{
		cin >> cmd >> first >> second;
		//first번째 수를 second로 바꾼다
		if (cmd == 1) {
			dif[first] = second;
		}
		//first-second번째수까지의 합 구하기
		else if (cmd == 2) {
			long long answer = sum_dp[second] - sum_dp[first-1];
			for (int j = first; j <= second; j++)
			{
				if (dif[j] != 0) {
					answer += dif[j] - number[j];
				}
			}
			cout << answer << "\n";

		}
	}


	return 0;
}