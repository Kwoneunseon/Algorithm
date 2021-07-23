#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n=1;
	vector<int> v;
	int arr[300000] = { 1, };
	cin >> n;
	while (n != 0) {
		cin >> n;
		v.push_back(n);
	}

	
	for (int i = 1; i <= v[v.size()-1]; i++)
	{
		if (arr[i] != 0) {
			for (int j = i * i; j <= v[v.size() - 1]; j += i)
			{
				if (arr[j] != 0)
					arr[j] = 0;
			}
		}
	}
	int first=0, last=1,cnt=0;
	while (true) {
		cnt = 0;
		for (int i = v[first]; i <= v[last]; i++)
		{
			if (arr[i] != 0)
				cnt++;
		}
		cout << cnt << "\n";
		first++;last++;
		if (last = v.size())
			break;
	}
	


	return 0;
}