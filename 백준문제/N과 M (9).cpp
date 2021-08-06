#include <iostream>
#include <vector>
#include <algorithm>

//이전과 마찬가지로 주소값반복을 막기 위해서 check
//달라진점은 같은 위치에 같은 숫자가 반복되는 것을 막는것이기 때문에
//백트래킹을 할 때마다 check_num을 초기화 시켜주며 확인해줘야 한다는 점이다.
using namespace std;

int n, m;
vector<int> v;

void back(vector<int>answer, int check[]) {
	if (answer.size() == m) {
		for (int i = 0; i < m; i++)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	//중복된 숫자가 나오지 않도록 확인하는 bool배열
	bool check_num[100001]{ false };

	for (int i = 0; i < n; i++)
	{
		if (check[i] != 1 && !check_num[v[i]]) {
			answer.push_back(v[i]);
			check_num[v[i]]=true;
			check[i] = 1; //idx 같은 주소값 사용을 막기 위해
			back(answer, check);
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
	back(answer, check);

	return 0;
}