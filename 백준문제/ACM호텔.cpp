#include <iostream>
using namespace std;

int main() {
	int h, w, n, T;
	cin >> T;
	while (T--) {
		cin >> h >> w >> n;
		if (n%h == 0) {//Ãþ
			cout << h;
			if (n / h < 10)
				cout << "0" << n / h;
			else
				cout << n / h;
		}
		else {
			cout << n % h;
			if (n / h < 9)
				cout << "0" << n / h+1;
			else
				cout << n / h+1;
		}
		
		cout << "\n";
	}

	return 0;
}