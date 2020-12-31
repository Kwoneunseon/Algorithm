#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

//다시 풀어보는 것을 추천한다.

using namespace std;

// 6,10일떄 610, 106중  610이 더 크다는 것을 알려주기 위해서.
bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;
	for (int i = 0; i < numbers.size(); i++)
	{
		temp.push_back(to_string(numbers[i]));
	}
	sort(temp.begin(), temp.end(),cmp);

	//0000인 경우 0으로 출력하기 위해서
	if (temp.at(0) == "0") return "0";
	
	for (auto num : temp) {
		answer += num;
	}
	return answer;
}

int main() {
	vector<int> numbers = { 6,10,2 };

	cout << solution(numbers);

	return 0;
}