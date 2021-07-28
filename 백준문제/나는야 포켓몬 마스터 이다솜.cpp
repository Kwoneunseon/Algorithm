#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int  main() {
	//항상 써주자!
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//map[key]=value
	map<string, int> pock_map;
	int m, n;
	string s;
	cin >> m >> n;
	string *pock_arr = new string[m + 1];
	for (int i = 1; i <= m; i++)
	{
		cin >> s;
		pock_map.insert({ s,i });
		pock_arr[i] = s;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			int temp = stoi(s);
			cout << pock_arr[temp]<<"\n";
		}
		else {
			cout << pock_map[s]<<"\n";
		}
	}

	return 0;
}