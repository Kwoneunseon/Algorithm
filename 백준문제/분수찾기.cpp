#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	int x = 1, y = 1, cnt = 1, idx = 1, n;
	bool move = false;
	cin >> n;
	while (cnt < n) {

		if (move) {
			if (y - 1 == 0) {
				x=  x+1;
				y = 1;
				move = false;
			}
			else {
				x = x + 1;
				y = y - 1;
			}
			

		}
		else {
			if (x- 1 == 0) {
				y = y + 1;
				x = 1;
				move = true;
			}
			else {
				x = x - 1;
				y = y + 1;
			}
		}

		cnt++;
	}
	cout << x << "/" << y;


	return 0;
}