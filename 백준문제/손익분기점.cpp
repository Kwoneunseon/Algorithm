#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ll a, b, c,answer;
	//a+bx < cx�� �Ǵ� x�� ���϶�
	cin >> a >> b >> c;

	if (c-b<=0)
		cout << -1;
	else {
		answer = a / (c-b);
		cout << answer + 1;
	}

	return 0;
}