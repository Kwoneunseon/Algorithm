#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	int answer = 0;
	stack<char> s;

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else {
			s.pop();
			if (str[i - 1] == '(') {
				answer += s.size();
			}
			else {
				answer++;
			}
		}

	}
	cout << answer;

	return 0;
}