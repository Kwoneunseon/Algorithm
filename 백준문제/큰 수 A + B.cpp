#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
//long long의 범위인 -2,147,483,648~2,147,483,647를 넘었기에
//string으로 하나하나씩 계산
int main() {
	string a, b, answer = "";
	int a_size, b_size, max_size, temp = 0;

	cin >> a >> b;
	a_size = a.length();b_size = b.length();
	max_size = max(a_size, b_size);
	vector<int> va, vb(max_size);
	bool flag = false;

	if (a_size < b_size) {
		for (int i = 0; i < b_size - a_size; i++)
		{
			a = '0' + a;
		}
	}
	else {
		for (int i = 0; i < a_size - b_size; i++)
		{
			b = '0' + b;
		}
	}


	for (int i = max_size - 1; i >= 0; i--)
	{
		if (flag) {
			temp = 1;
			flag = false;
		}

		temp = temp + (a[i] - '0') + (b[i] - '0');

		if (temp > 9) {
			flag = true;
			temp = temp - 10;
		}
		answer.push_back(temp + '0');
		temp = 0;
	}
	if (flag)
		answer.push_back('1');

	reverse(answer.begin(), answer.end());
	cout << answer;

	return 0;
}