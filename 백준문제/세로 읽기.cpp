#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string>v;
	string s;
	bool flag = true;
	int max=0,idx = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	while (flag) {
		flag = false;
		for (int i = 0; i < 5; i++)
		{
			if (v[i].length() > idx) {
				cout << v[i][idx];
				flag = true;
			}
		}
		idx++;
	}

	return 0;
}