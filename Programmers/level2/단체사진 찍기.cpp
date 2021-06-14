#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isRight(char comp, int c_diff, int r_diff) {
	if (comp == '=')
		return c_diff == r_diff;
	else if (comp == '<')
		return r_diff < c_diff;
	else if (comp == '>')
		return r_diff > c_diff;
}

int solution(int n, vector<string> data) {
	int answer = 0;
	string friends = "ACFJMNRT";
	do {
		bool flag = true;
		for (string text : data) {
			char first = text[0];
			char second = text[2];
			char comp = text[3];
			int c_diff = text[4]-'0'; //Á¶°Ç

			int r_diff = friends.find(first) - friends.find(second);
			r_diff = abs(r_diff) - 1;
			if (isRight(comp, c_diff, r_diff))continue;
			flag=  false;
			break;
		}
		if (flag == true) answer++;

	} while (next_permutation(friends.begin(), friends.end()));


	return answer;
}