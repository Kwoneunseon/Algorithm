#include <iostream>
#include <string>

using namespace std;

string change(int numA, int numB) {
	string s;
	for (int i = 0; i < numA; i++)
	{
		s += "AAAA";
	}
	for (int i = 0; i < numB; i++)
	{
		s += "BB";
	}
	return s;
}

int main() {
	string s, answer = "";
	bool flag = true;
	int count = 0, numA, numB;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'X') {
			count++;
			if (i == s.length() - 1) {
				numA = count / 4;
				count = count % 4;
				numB = count / 2;
				count = count % 2;
				if (count != 0) {
					flag = false;
					break;
				}
				else {
					answer += change(numA, numB);
				}

			}
		}
		else if (s[i] == '.') {
			numA = count / 4;
			count = count % 4;
			numB = count / 2;
			count = count % 2;
			if (count != 0) {
				flag = false;
				break;
			}
			else {
				answer += change(numA, numB);
			}
			answer += ".";
		}

	}
	if (flag)
		cout << answer;
	else
		cout << -1;

	return 0;
}