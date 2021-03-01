#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string temp;
	int a, b;
	while (T--) {

		cin >> temp;
		a = temp[0] - '0';
		b = temp[1] - '0';
		cout << a + b << "\n";
	}

	return 0;
}