#include <iostream>
#include <string>

using namespace std;

string change_max(string s){
	string number="";
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'M') {
			count++;
			if (i == s.length() - 1) {
				for (int j = 0; j < count; j++)
				{
					number += '1';
				}
			}
		}
		else if (s[i] == 'K') {
			number += '5';
			for (int j = 0; j < count; j++)
			{
				number += '0';
			}
			count = 0;
		}
	}
	return number;
}

string change_min(string s) {
	string number = "";
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'M') {
			count++;
			if (i == s.length() - 1) {
				for (int j = 0; j < count; j++)
				{
					if (j == 0)
						number += '1';
					else
						number += '0';
				}
			}
		}
		else if (s[i] == 'K') {
			for (int j = 0; j < count; j++)
			{
				if (j == 0)
					number += '1';
				else
					number += '0';
			}
			count = 0;
			number += '5';
		}
	}
	return number;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	cout << change_max(s)<<"\n"<<change_min(s);


	return 0;
}