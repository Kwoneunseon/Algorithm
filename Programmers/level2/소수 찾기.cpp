#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//���۸� ��.
//�����佺�׳׽��� ü�� �̿��Ѵ�.

bool check(int number, string s) {
	vector<bool>visited(s.size());

	while (number) {
		bool flag = false;//temp�� s�ȿ� ���ԵǴ��� �ƴ��� Ȯ���� ���ؼ�
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
	vector<bool>arr(stoi(numbers)+1, false); // �����佺�׳׽��� ü �̿�
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
