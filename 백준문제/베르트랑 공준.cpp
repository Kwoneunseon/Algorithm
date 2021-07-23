#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 1, max = -1;
	vector<int> v;

	while (true) {
		cin >> n;
		if (n == 0)
			break;
		v.push_back(n);
		if (max < n)
			max = n;
	}
	int *arr = new int[2 * max+1];
	for (int i = 1; i <= 2*max; i++)
	{
		arr[i] = 1;
	}
	arr[1] = 0;
	for (int i = 2; i <= 2*max; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j =i*2; j <= 2*max; j+=i)
		{
			arr[j] = 0;
		}
	}
	int cnt=0;
	
	for (int i = 0; i < v.size(); i++)
	{
		cnt = 0;
		for (int j = v[i]+1; j <= 2*v[i]; j++)
		{
			if (arr[j] != 0)
				cnt++;

		}
		cout << cnt << "\n";

	}


	return 0;
}