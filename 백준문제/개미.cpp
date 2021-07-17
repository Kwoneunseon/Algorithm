#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int a_size, b_size,T;
	string a, b;
	int cnt = 0, idx = 0;
	cin >> a_size >> b_size >> a >> b >> T;
	vector<pair<char, int> >v;
	//a ют╥б
	for (int i = a_size-1; i >= 0; i--)
	{
		v.push_back({ a[i],0 });
	}
	for (int i = 0; i < b_size; i++)
	{
		v.push_back({ b[i],1 });
	}
	pair<char, int> temp;
	while (cnt != T) {
		for (int i = 0; i < v.size()-1; i++)
		{
			if (v[i].second == 0 && v[i + 1].second == 1) {
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				i += 1;
			}
		}
		cnt++;

	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first;
	}


	return 0;
}