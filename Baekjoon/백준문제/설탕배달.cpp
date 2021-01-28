#include <iostream>
using namespace std;

int main() {
	int n , temp ,cnt;
	cin >> n;
	temp = -1;
	for (int i = n/5; i >= 0; i--)
	{
		int k = n - 5 * i;
		if (k % 3 == 0) {
			temp = i + k / 3;
			break;
		}
	}
	cout << temp;




	system("pause");
	return 0;
}