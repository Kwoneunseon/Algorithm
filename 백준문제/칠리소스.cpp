#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long c;
	cin >> c;
	int answer=0, digit=1;
	while (c) {
		answer += (c % 7)*digit;
		c /= 7;
		digit *= 3;
	}
	cout << answer;

	


	return 0;
}