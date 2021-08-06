#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

void repeat(vector<int> v, int arr[]) {
	if (v.size() == m) {
		sort(v.begin(), v.end());
		for (int i = 0; i < m; i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = (v.size() == 0 ? 1 : v[v.size() - 1]); i <= n; i++)
	{
		v.push_back(i);
		repeat(v, arr);
		//�Էµ� ���� ����
		v.erase(v.begin() + v.size() - 1, v.begin() + v.size());

	}

}

int main() {
	cin >> n >> m;
	vector<int> answer;
	int *arr = new int[n + 1];
	arr[0] = 1;//������� ���� ���̱⿡ �̸� üũ�س���.
	repeat(answer, arr);


	return 0;
}