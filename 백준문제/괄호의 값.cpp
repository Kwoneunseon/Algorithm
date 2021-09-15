#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<char>st;
	string s;
	cin >> s;
	bool impossible = false;
	int temp = 1, answer = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') {
			temp *= 2;
			st.push('(');
		}
		else if (s[i] == '[') {
			temp *= 3;
			st.push('[');
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() != '[') {
				impossible = true;
				break;
			}
			else {
				if (s[i - 1] == '[')
					answer += temp;
				temp /= 3;
				st.pop();
			}
		}
		else if (s[i] == ')' ) {
			if (st.empty() || st.top() != '(') {
				impossible = true;
				break;
			}
			else {
				if (s[i - 1] == '(')
					answer += temp;
				temp /= 2;
				st.pop();
			}
		}
	}

	if (impossible || !st.empty())
		cout << 0;
	else
		cout << answer;

	return 0;
}