#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
//idx : 전과 달리 idx를 기억해서 그 이후의 요소들만 확인해야함.
void back(vector<int>answer, int check[], int idx) {
	if (answer.size() == m) {
		for (int i = 0; i < m; i++)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (check[i] != 1) {
			answer.push_back(v[i]);
			check[i] = 1;
			back(answer, check, i + 1);
			check[i] = 0;
			answer.erase(answer.begin() + answer.size() - 1, answer.begin() + answer.size());
		}
	}

}

int main() {
	cin >> n >> m;
	int temp;
	vector<int> answer;
	int *check = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	back(answer, check, 0);

	return 0;
}