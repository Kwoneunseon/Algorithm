//2437
//�׸���
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, temp;
	vector<int> weight;
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		cin >> temp;
		weight.push_back(temp);
	}
	int answer = 1; //���� ����  +1�� ����� �ϱ⶧��.
	sort(weight.begin(), weight.end());
	for (int i = 0; i < n; i++)
	{
		if (weight[i] > answer)
			break;
		answer += weight[i];
	}
	cout << answer;

	return 0;
}