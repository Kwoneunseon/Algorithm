#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, R;
	string s;
	cin >> T;
	while (T--) {
		cin >> R >> s;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j= 0; j < R; j++)
			{
				cout << s[i];
			}
		}
		cout << "\n";
	}


	return 0;
}