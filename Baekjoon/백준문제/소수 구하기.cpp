//1929
//에라토스테네스의 체 사용
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int first, last;
	cin >> first >> last;
	int *arr = new int[last + 1];
	arr[1] = 1;
	for (int i = 2; i <= last; i++)
	{
		for (int j = i+i; j <= last; j+=i)
		{
			arr[j] = 1;
		}
	}
	for (int i =first; i <= last; i++)
	{
		if (arr[i] != 1) {
			cout << i << "\n";
		}
	}

	return 0;
}