#include <iostream>	
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string a;
		int b;
		cin >> a >> b;
		int c = (a[0] - '0') % b;
		for (int i = 1; i < a.length(); i++)
		{
			c = (c * 10 + (a[i] - '0')) % b;
		}
		if (c == 0) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}