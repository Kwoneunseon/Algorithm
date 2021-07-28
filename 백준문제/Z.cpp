#include <iostream>
using namespace std;

int r, c, ans = 0;

void find(int y, int x, int size) {
	if (r==y&&c==x) {
		cout << ans;
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x) {
		
		//1사분면 탐색
		find(y, x, size / 2);
		//2사분면 탐색
		find(y, x + size / 2, size / 2);
		//3사분면 탐색
		find(y + size / 2, x, size / 2);
		//4사분면 탐색
		find(y + size / 2, x + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}

int main() {
	int n;
	cin >> n >> r >> c;
	//2^n은 1<<n으로 표현함.
	//1을 1칸 옮기면 2진수 (10) = 2;
	//1을 2칸 옮기면 2진수 (100) = 4; 이 구조로

	find(0, 0, 1 << n);


	return 0;
}