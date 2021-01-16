#include <vector>
#include <string>
using namespace std;

string numbers = { '1','2','4' };

string solution(int n) {
	string answer = "";
	vector<int> idx;
	idx.push_back(n);
	while (true) {
		vector<int> temp;
		bool flag = true;
		for (int j = 0; j < idx.size(); j++)
		{
			if (idx[j] > 3) {
				if (idx[j] % 3 == 0) {
					temp.push_back(3);
					temp.push_back(idx[j] / 3 - 1);
				}
				else {
					temp.push_back(idx[j] % 3);
					temp.push_back(idx[j] / 3);
				}
			}
			else {
				temp.push_back(idx[j]);
			}
		}
		idx = temp;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] > 3) {
				flag = false;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	
	for (int i = idx.size()-1; i >=0; i--)
	{
		answer.push_back(numbers[idx[i]-1]);
	}
	return answer;
}


//다른 사람 풀이

string numbers = { '4','1','2'};

string other_solution(int n) {
	string answer ="";
	int a;
	while (n > 0) {
		a = n % 3;
		n = n / 3;
		if (a == 0) {
			n -= 1;
		}
		answer = numbers[a] + answer;
	}
	return answer;
}