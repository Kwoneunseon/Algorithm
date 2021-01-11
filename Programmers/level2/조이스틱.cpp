#include <vector>
#include <string>

using namespace std;

int solution(string name) {
	int answer = 0, i =0;

	string temp(name.length(), 'A');
	while (true) {
		temp[i] = name[i];
		temp[i] - 'A' > 'Z' + 1 - temp[i] ? answer += 'Z' + 1 : answer += temp[i] - 'A';
		if (temp == name) break;
		for (int move = 0; move < name.length(); move++)
		{
			if (name[(i + move) % name.length()] != temp[(i + move) % name.length()]) {
				i = (i + move) % name.length();
				answer += move;
				break;
			}
			else if (name[(i + name.length() - move) % name.length()]
				!= temp[(i + name.length() - move) % name.length()]) {
				i = (i + name.length() - move) % name.length();
				answer += move;
				break;
			}
		}
	}
	return answer;
}