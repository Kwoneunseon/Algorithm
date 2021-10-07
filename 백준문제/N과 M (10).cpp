#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n, m;
void back(vector<int> answer, int check[],int idx) {
	if (answer.size() == m) {
		for (int i = 0; i < m; i++)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	bool check_num[10001]{ false };

	for (int i = idx; i < n; i++)
	{
		if (check[i] != 1 && !check_num[v[i]]) {
			check[i] = 1;
			check_num[v[i]] = true;
			answer.push_back(v[i]);
			back(answer, check,idx++);
			check[i] = 0;
			answer.erase(answer.begin() + answer.size() - 1, answer.begin() + answer.size());
		}
	}

}

int main() {
	cin >> n >> m;
	int temp;
	vector<int> answer;
	int * check = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	back(answer, check, 0);
	return 0;
}