//2021.02.26-º¹½À
#include <vector>
#include <string>

using namespace std;

string solution(int n) {
	string answer = "";
	string str = "0124";
	vector<int> v;
	while (n != 0) {
		v.push_back(n % 3);
		n /= 3;
	}
	bool check = true;
	while (check) {
		check = false;
		for (int i = v.size()-1; i >= 0; i--)
		{
			if (v[i] == 0 && i<v.size()-1) {
				check = true;
				v[i] = 3;
				v[i + 1] = v[i + 1] - 1;
			}
		}
	}

	for (int i = v.size()-1; i >=0; i--)
	{
		if (v[i] != 0) {
			answer.push_back(str[v[i]]);
		}
	}

	return answer;
}

int main() {
	solution(12);
	return 0;
}