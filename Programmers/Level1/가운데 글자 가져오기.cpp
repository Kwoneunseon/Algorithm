//2021.02.25
#include <string>

using namespace std;

string solution(string s) {
	string answer = "";
	if (s.length() % 2 == 1) {
		answer += s[s.length() / 2];
	}
	else if (s.length() % 2 == 0) {
		answer += s[s.length() / 2 - 1];
		answer += s[s.length() / 2];
	}

	return answer;
}