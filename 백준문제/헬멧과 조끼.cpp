#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int>helmet(N), vest(M);
	for (int i = 0; i < N; i++)
	{
		cin >> helmet[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> vest[i];
	}
	sort(helmet.rbegin(), helmet.rend());
	sort(vest.rbegin(), vest.rend());

	int answer = 0;

	answer = helmet[0] + vest[0];
	cout << answer;

	return 0;
}