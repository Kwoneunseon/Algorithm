#include <iostream>
#include<string>
#include <queue>
using namespace std;

string check(string s) {
	for (int i = 0; i < s.size()-1; i++)
	{
		if (s[i] == s[i + 1]) {
			s[i] = '0', s[i + 1] = '0';
		}
	}
	return s;
}

int solution(string s)
{
	int answer = 0;
	string temp;
	bool flag = true;
	while (true) {
		temp = check(s);
		if (count(temp.begin(), temp.end(), '0') == 0)
			break;
		s = "";
		for (int i = 0; i < temp.size(); i++)
		{
			if(temp[i]!='0')
				s.push_back(temp[i]);
		}
		if (s == "") {
			answer = 1;
			break;
		}
	}

	return answer;
}

int main() {
	string s;
	cin >> s;
	cout<<solution(s);
	return 0;

}