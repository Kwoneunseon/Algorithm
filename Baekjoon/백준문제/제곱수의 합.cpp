#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int num;
	cin >> num;
	int *arr = new int[num + 1];
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= num; i++)
	{
		arr[i] = i;
		for (int j = 1; j <= sqrt(i); j++)
		{
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}

	cout << arr[num];
	return 0;
}
