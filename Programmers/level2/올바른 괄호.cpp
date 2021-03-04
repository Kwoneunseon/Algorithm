#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s) {
	bool answer = true;
	stack<char>check;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			check.push(s[i]);
		else {
			if (check.empty()) {
				answer = false;
				break;
			}
			check.pop();
		}
	}
	if (!check.empty())
		answer = false;

	return answer;
}