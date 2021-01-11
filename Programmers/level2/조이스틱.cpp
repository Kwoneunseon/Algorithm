
#include <vector>
#include <string>

using namespace std;

int solution(string name) {
	int answer = 0, i = 0;
	string temp(name.length(), 'A');

	while (true) {
		name[i] - 'A' < 'Z'- name[i] +1 ? answer += name[i] - 'A' : answer += 'Z'- name[i] + 1;
		temp[i] = name[i];
		if (temp == name)
			break;
		for (int move = 1; move < name.length(); move++)
		{
			//오른쪽으로 움직일지
			if (temp[(i + move) % name.length()] != name[(i + move) % name.length()]) {
				i = (i + move) % name.length();
				answer += move;
				break;
			}
			//왼쪽으로 움직일 지
			else if(temp[(i + name.length() - move) % name.length()] != name[(i + name.length() - move) % name.length()]) {
				i = (i + name.length() - move) % name.length();
				answer += move;
				break;
			}
		}
	}

	return answer;
}
