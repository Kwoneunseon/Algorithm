//2847
//±×¸®µð
#include <iostream>

using namespace std;

int main() {
	int n,cnt=0;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n-1; i >=1; i--)
	{
		while (arr[i]-1 < arr[i - 1]) {
			arr[i - 1]--;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}