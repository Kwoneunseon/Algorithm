//1316
//¹®ÀÚ¿­
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int check[27];

int main() {
	int n,cnt=0;
	bool flag = true;
	string temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		memset(check, 0, sizeof(check));
		flag = true;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			if (check[temp[j] - 'a'] != 0) {
				if (j > 0) {
					if (temp[j] != temp[j - 1]) {
						flag = false;
						break;
					}
				}
			}
			check[temp[j] - 'a']++;
		}
		if (flag)
			cnt++;
	}
	
	cout << cnt;

	return 0;
}