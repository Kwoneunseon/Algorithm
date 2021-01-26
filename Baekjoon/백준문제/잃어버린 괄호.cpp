//1541번
//그리디 알고리즘

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string exp , operators,temp;
	vector<int> num;
	int idx = 0,min=0,minus_idx = 50,oper_idx = 0;
	cin >> exp;
	while (idx < exp.size()) {
		if (exp[idx] == '-' || exp[idx] == '+') {
			if (exp[idx] == '-' && minus_idx == 50)
				minus_idx = oper_idx;
			num.push_back(stoi(temp));
			operators.push_back(exp[idx]);
			temp = "";
			oper_idx++;
		}
		else {
			temp += exp[idx];
			if (idx == exp.size() - 1) {
				num.push_back(stoi(temp));
			}
		}
		idx++;
	}
	for (int i = 0; i < num.size(); i++)
	{
		if (i > minus_idx) {
			min -= num[i];
		}
		else {
			min += num[i];
		}
	}
	cout << min;
	return 0;
}