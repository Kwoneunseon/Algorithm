#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	while (true) {
		string s;
		bool answer = true;
		getline(cin, s);
		if (s == ".")
			break;
		cout << s<<"\n";
		stack<char>st;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					answer = false;
					break;
				}
				else
					st.pop();
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() != ']') {
					answer = false;
					break;
				}
				else
					st.pop();
			}
		}
		if (answer)
			cout << "yes\n";
		else
			cout << "no\n";

	}
	



	return 0;
}