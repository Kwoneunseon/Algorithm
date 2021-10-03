#include <iostream>

using namespace std;

int n, answer = 0;

bool used1[40],used2[40],used3[40];
//used1 : 같은 행에서 열 중복 확인
//used2 :(왼->오 기준)내려가는 대각선 확인
//used3 : (왼->오 기준)올라가는 대각선 확인

void BackTracking(int row) {
	if (row == n) {
		answer++;
		return;
	}
	for (int col = 0; col < n; col++)
	{
		if (used1[col] || used2[col + row] || used3[row - col + n - 1])
			continue;
		used1[col] = true;
		used2[col + row] = true;
		used3[row - col + n - 1] = true;
		BackTracking(row + 1);
		used1[col] = false;
		used2[row+col] = false;
		used3[row - col + n - 1] = false;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	BackTracking(0);
	cout << answer;

	return 0;
}