#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, k, cnt = 0;//n : 사람의 수, k는 몇번째 삶을 제거할지
	cin >> n >> k;
	queue<int>q;
	vector<int>returns;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	int temp;
	while (q.size()) {
		temp = q.front();
		q.pop();
		cnt++;
		if (cnt == k) {
			returns.push_back(temp);
			cnt = 0;
		}
		else
			q.push(temp);
	}


	cout << "<";
	for (int i = 0; i < n; i++)
	{
		cout << returns[i];
		if (i != n - 1)
			cout << ", ";
		else
			cout << ">";
	}

	return 0;
}