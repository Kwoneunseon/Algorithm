#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//구글링 함.
//에라토스테네스의 체를 이용한다.

bool check(int number, string s) {
	vector<bool>visited(s.size());

	while (number) {
		bool flag = false;//temp가 s안에 포함되는지 아닌지 확인을 위해서
		int temp = number % 10;
		for (int i = 0; i < s.size(); i++)
		{
			if (temp == (s[i] - '0') && visited[i] == false) {
				visited[i] = true;
				flag = true;
				break;
			}
		}
		if (flag == false) {
			return false;
		}

		number /= 10;
	}
	return true;
}
int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>());
	vector<bool>arr(stoi(numbers)+1, false); // 에라토스테네스의 체 이용
	for (int i = 2; i <= stoi(numbers); i++)
	{
		if (!arr[i] && check(i, numbers)) answer++;
		if (!arr[i]) {
			for (int j= i*2; j <= stoi(numbers); j +=i)
			{
				arr[j] = true;
			}
		}
	}
	return answer;
}
