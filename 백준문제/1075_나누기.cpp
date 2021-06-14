#include <iostream>

using namespace std;

int main() {

	int N, K,answer;
	cin >> N >> K;
	int temp = N / 100;
	N = temp * 100; //뒷자리를 00으로 맞춰준다.
	temp = N % K; // 나온 나머지를 뺀 수에 K에 값을 더하면 답을 구할수 있음.
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