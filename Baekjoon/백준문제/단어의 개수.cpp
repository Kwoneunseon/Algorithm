//1152
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	vector<string>s;
	string temp;
	getline(cin, temp);
	istringstream ss(temp);
	string stringBuffer;
	while (getline(ss, stringBuffer, ' ')) {
		s.push_back(stringBuffer);
	}
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != "") {
			cnt++;
		}
	}
	cout << cnt;
			
	return 0;
}