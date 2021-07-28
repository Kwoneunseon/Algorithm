#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n,temp;
	string s;
	cin >> m >> n;
	vector<string>dic(m+1);
	for (int i = 1; i <= m; i++)
	{
		cin >> dic[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			temp = stoi(s);
			if (temp >= 1 && temp < m) {
				cout << dic[temp] << "\n";
			}
		}
		else {
			auto it = find(dic.begin(), dic.end(), s);
			cout << it - dic.begin()<<"\n";
		}
	}
	

	return 0;
}