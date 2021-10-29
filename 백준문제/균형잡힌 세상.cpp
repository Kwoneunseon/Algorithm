#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (true) {
		string s;
		//균형잡힌 문자열인지 체크하는 변수 = answer
		bool answer = true;
		getline(cin, s);
		//.만들어올 경우 종료
		if (s == ".")
			break;
		stack<char>st;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				// )가 들어올 때, stack이 비워져있거나 stack의 top이 (이 아닐 경우
				if (st.empty() || st.top() != '(') {
					answer = false;
					break;
				}
				else
					st.pop();
			}
			else if (s[i] == ']') {
				//]가 들어올 때, stack이 비워져있거나 stack의 top이[이 아닐 경우
				if (st.empty() || st.top() != '[') {
					answer = false;
					break;
				}
				else
					st.pop();
			}
		}
		//st이 비워져있는지 확인해야한다. (이부분 때문에 첫번째 시도 때 틀림)
		if (answer && st.empty())
			cout << "yes\n";
		else
			cout << "no\n";

	}
	



	return 0;
}