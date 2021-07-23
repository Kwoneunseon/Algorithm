#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int T,max = -1;
	cin >> T;
	vector<int> v(T);
	for (int i = 0; i < T; i++)
	{
		cin >> v[i];
		if (max < v[i])
			max = v[i];
	}
	int *arr = new int[max + 1];
	for (int i = 1; i <= max; i++)
	{
		arr[i] = i;
	}
	arr[1] = 0;
	for (int i = 2; i <= max; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j =i*i;j <= max; j+=i)
		{
			if (arr[j] != 0)
				arr[j] = 0;
		}
	}
	int a=-1, b=-1;
	for (int j = 0; j < T; j++)
	{
		for (int i =1; i <= ceil((double)v[j]/(double)2); i++)
		{
			if (arr[i] != 0 && arr[v[j] - i] != 0) {
				a = arr[i];
				b = arr[v[j] - i];
			}
		}
		cout << a << " " << b << "\n";
	}

	return 0;
}