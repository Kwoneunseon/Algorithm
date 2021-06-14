//1377
#include <iostream>

using namespace std;

int arr[500000];
int main() {
	bool change = false;
	int n,temp;
	cin >> n;
	for (int i = 1; i <=  n; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}
	for (int i = 1; i <= n + 1; i++)
	{
		change = false;
		for (int j = 1; j <= n - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				change = true;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (change == false) {
			cout << i << "\n";
			break;
		}
	}


	return 0;
}