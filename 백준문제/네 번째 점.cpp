#include <iostream>

using namespace std;

int main() {
	int new_x, new_y;
	int x[3] = { 0, }, y[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		cin >> new_x >> new_y;
		x[i] = new_x;y[i] = new_y;
		for (int j = 0; j < i; j++)
		{
			if (x[j] == new_x) {
				x[j] = 0;
				x[i] = 0;
			}
			if (y[j] == new_y) {
				y[j] = 0;
				y[i] = 0;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (x[i] != 0) {
			cout << x[i]<<" ";
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (y[i] != 0) {
			cout << y[i];
			break;
		}
	}

	return 0;
}