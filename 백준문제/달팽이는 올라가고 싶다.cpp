#include <iostream>
using namespace std;

int main() {
	int a, b, v,answer;//a : 올라가는 높이, b: 떨어지는 높이, v: 목표
	cin >> a >> b >> v;
	//(a-b)x+b>=v의 를 만족하는 x의 최소값(x는 항상 정수)
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