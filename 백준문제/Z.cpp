#include <iostream>
using namespace std;

int r, c, ans = 0;

void find(int y, int x, int size) {
	if (r==y&&c==x) {
		cout << ans;
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x) {
		
		//1��и� Ž��
		find(y, x, size / 2);
		//2��и� Ž��
		find(y, x + size / 2, size / 2);
		//3��и� Ž��
		find(y + size / 2, x, size / 2);
		//4��и� Ž��
		find(y + size / 2, x + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}

int main() {
	int n;
	cin >> n >> r >> c;
	//2^n�� 1<<n���� ǥ����.
	//1�� 1ĭ �ű�� 2���� (10) = 2;
	//1�� 2ĭ �ű�� 2���� (100) = 4; �� ������

	find(0, 0, 1 << n);


	return 0;
}