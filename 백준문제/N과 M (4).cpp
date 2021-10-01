#include <iostream>

using namespace std;

int n, m;

void func(int* arr, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	int st = 1;
	if (k != 0) st = arr[k - 1];
	for (int i = st; i <= n; i++)
	{
		arr[k] = i;
		func(arr, k + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int *arr = new int[m];
	func(arr, 0);

	return 0;
}