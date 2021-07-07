#include <iostream>
typedef long long ll;

using namespace std;

int main() {
	ll count = 0, first=1, second=1,n;
	cin >> n;
	while (true) {
		if (first <= n && n <= second)
			break;
		count++;
		first = second + 1;
		second = first + 6 * count -1;
	}
	cout << count+1;

	return 0;
}