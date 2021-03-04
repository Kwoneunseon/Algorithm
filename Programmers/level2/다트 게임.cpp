//2020.09.04
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> val;
	for (int i = 0; i < dartResult.size(); i++)
	{
		if (dartResult[i] == '*') {
			if (val.size() == 1) {
				val[0] *= 2;
			}
			else {
				val[val.size() - 1] *= 2;
				val[val.size() - 2] *= 2;
			}
		}
		else if (dartResult[i] == '#') {
			val[val.size() - 1] *= -1;
		}
		else {
			int value = dartResult[i]-'0';
			if (dartResult[i + 1] == '0') {
				value = 10;
				i++;
			}
			if (dartResult[i+1] == 'S') {
				val.push_back(pow(value, 1));
			}
			else if (dartResult[i+1] == 'D') {
				val.push_back(pow(value, 2));
			}
			else if (dartResult[i+1] == 'T') {
				val.push_back(pow(value, 3));
			}
			i++;
		}
	}

	for (int i = 0; i < val.size(); i++)
	{
		answer += val[i];
	}
	return answer;
}

int main() {
	int temp = solution("1D2S#10S");
	cout << temp;

	return 0;
}