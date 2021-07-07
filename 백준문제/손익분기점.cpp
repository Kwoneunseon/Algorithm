#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ll a, b, c,answer;
	//a+bx < cx이 되는 x를 구하라
	cin >> a >> b >> c;

	if (c-b<=0)
		cout << -1;
	else {
		answer = a / (c-b);
		cout << answer + 1;
	}

	return 0;
}