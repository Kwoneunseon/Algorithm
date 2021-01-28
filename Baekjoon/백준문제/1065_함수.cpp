#include <iostream>
using namespace std;

int func(int a, int b, int c) {
	if (b - a == c - b)
		return 1;
	else
		return 0;
}
int main() {
	int number;
	int count = 0;
	cin >> number;
	if (number < 100)
		count = number;
	else if (number >= 100) {
		count += 99;
		for (int i = 100; i <= number; i++)
		{
			int k = i;
			int first = k / 100;
			k = k - first * 100;
			int sec = k / 10;
			k = k - sec * 10;
			int third = k;
			if (func(first, sec, third) == 1)
				count++;
		}
	}

	cout << count;
	system("pause");
	return 0;
}

/*
	for (int i = 0; i <= number; i++)
	{
		if (number < 100) {
			count = number;
			break;
		}
		else if(i>=100){
			count += 99;
			int first = i / 100;
			number = i - first * 100;
			int sec = i / 10;
			i = i - sec * 10;
			int third = i;
			if (func(first, sec, third) == 1)
				count++;

		}
	}
*/