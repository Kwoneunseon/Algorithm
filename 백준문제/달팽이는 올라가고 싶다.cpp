#include <iostream>
using namespace std;

int main() {
	int a, b, v,answer;//a : �ö󰡴� ����, b: �������� ����, v: ��ǥ
	cin >> a >> b >> v;
	//(a-b)x+b>=v�� �� �����ϴ� x�� �ּҰ�(x�� �׻� ����)
	a = a - b;
	answer = (v - b) % a;
	if (answer == 0) {
		answer = (v - b) / a;
	}
	else
		answer = (v - b) / a + 1;
	cout << answer;

	return 0;
}