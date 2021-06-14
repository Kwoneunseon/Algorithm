//2455
//¼öÇĞ
#include <iostream>
using namespace std;

int main() {
	int add, sub, sum = 0,max= 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> sub >> add;
		sum += add;
		sum -= sub;
		if (max < sum)
			max = sum;

	}
	cout << max;
	return 0;
}