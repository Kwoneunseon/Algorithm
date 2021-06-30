#include <iostream>
#include<string>

using namespace std;
// 테스트 케이스 1번 에서 막힘
int solution(string s)
{
	int answer = 0;
	string temp;
	bool flag = true;
	char prev;
	while (flag) {
		if (s.size() % 2 == 1) {
			break;
		}//홀수는 무조건 false
		flag = false;
		prev = s[0];
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != prev) {
				temp.push_back(prev);
				prev = s[i];
				if (i == s.size() - 1)
					temp.push_back(s[i]);
			}
			else {
				flag = true;
				if (temp.empty()) {
					prev = s[i + 1];
					i++;
				}
				else {
					prev = temp[temp.size() - 1];
					temp.erase(temp.begin() + temp.size() - 1, temp.begin() + temp.size());
				}
			}
		}
		if (temp.empty()) {
			answer = 1;
			break;
		}
		else {
			s = temp;
			temp = "";
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