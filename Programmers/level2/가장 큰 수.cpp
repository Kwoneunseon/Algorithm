#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

//�ٽ� Ǯ��� ���� ��õ�Ѵ�.

using namespace std;

// 6,10�ϋ� 610, 106��  610�� �� ũ�ٴ� ���� �˷��ֱ� ���ؼ�.
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

	//0000�� ��� 0���� ����ϱ� ���ؼ�
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