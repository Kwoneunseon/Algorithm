#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

//다시 풀어보는 것을 추천한다.

using namespace std;

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