//복습 - 2021.02.27
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//소수 숫자들이  string안에 있는지 확인
bool check(int number, string s) {
	vector<bool>visited(s.size(), false);

	while (number != 0) {
		bool flag = false;
		int temp = number % 10;
		for (int i = 0; i < s.size(); i++)
		{
			if (temp == (s[i]-'0') && !visited[i]) {
				flag = true;
				visited[i] = true;
				break;
			}
		}
		if (!flag)return false;
		number /= 10;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>());
	vector<bool>v(stoi(numbers) + 1, false);
	for (int i =2; i <= stoi(numbers); i++)
	{
		if (!v[i] && check(i, numbers))answer++;
		if (!v[i]) {
			for (int j = i*2; j <= stoi(numbers); j+=i)
			{
				v[j] = true;
			}
		}
	}


	return answer;
}

int main() {
	solution("011");
	return 0;
}