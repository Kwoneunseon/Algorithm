#include <vector>
#include <string>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int index = -1;
	for (int i = 0; i < number.length()-k;i++)
	{
		char max = '0';
		for (int j = index+1; j <= k+i; j++)
		{
			if (max < number[j]) {
				max = number[j];
				index = j;
			}
		}
		answer += max;
	}
	   
	return answer;
}

//획기적인 다른 사람 풀이
string solution(string number, int k) {
	string answer = "";
	answer = number.substr(k);
	for (int i = k-1; i >= 0; i--)
	{
		int j = 0;
		do {
			if (number[i] >= answer[j]) {
				char temp = answer[j];
				answer[j] = number[i];
				number[i] = temp;
				j++;
			}
			else {
				break;
			}
		} while (true);
	}

	return answer;
}