#include <iostream>

using namespace std;

int main() {

	int N, K,answer;
	cin >> N >> K;
	int temp = N / 100;
	N = temp * 100; //���ڸ��� 00���� �����ش�.
	temp = N % K; // ���� �������� �� ���� K�� ���� ���ϸ� ���� ���Ҽ� ����.
	if (temp == 0)
		answer = 0;
	else
	 answer = K - temp;

	if (answer < 10)
		cout << 0 << answer;
	else
		cout << answer;



	system("pause");
	return 0;
}