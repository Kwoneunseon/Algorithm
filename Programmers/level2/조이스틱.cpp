
#include <vector>
#include <string>
#include <algorithm>
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

//다른사람의 풀이
int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
//미리 움직여야하는 횟수를 계산한다.

int other_solution(string name) {
	int answer = 0;
	for (auto ch : name)
		answer += LUT[ch - 'A'];
	int len = name.length();
	int left_right = len - 1;
	for (int i = 0; i < len; ++i)
	{
		int next_i = i + 1;
		//A가 아닌 char가 i를 기준으로 어디에 있는지 파악.
		while (next_i < len && name[next_i] == 'A') {
			next_i++;
		}
		// 이부분이 이해가 잘 안감.(다시)
		left_right = min(left_right, i + len - next_i + min(i, len - next_i));
	}

	answer += left_right;
	return answer;
}