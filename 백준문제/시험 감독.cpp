#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N , b,c;// b: 총감독관, c : 부감독관
	//경계값에 대해서 생각해야돼
	//B,C가 1일고 N이 1,000,000일때 답이 int 범위를 넘기때문에
	long long answer= 0;
	cin >> N;
	int* room = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> room[i];
	}
	cin >> b >> c;
	for (int i = 0; i < N; i++)
	{
		answer++;
		room[i] = room[i] - b;
		if (room[i] > 0) {
			answer += room[i] / c;
			if (room[i] % c != 0)
				answer++;
		}
	}
	cout << answer;

	return 0;
}