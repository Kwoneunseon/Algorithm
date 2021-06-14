#include <iostream>
using namespace std;

int main() {
	char value[5] = { 'D','C','B','A','E' };
	int temp, sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> temp;
			if (temp) {
				sum++;
			}
		}
		cout << value[sum]<<"\n";
	}
	return 0;
}
