#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//binary search 사용함.
//참조 블로그 : https://jaimemin.tistory.com/672

using namespace std;

vector<string> no_listen, result;

bool binary_search(int low, int high, string name) {
	if (low > high)
		return false;
	else {
		int mid = (low + high) / 2;

		if (no_listen[mid] == name)
			return true;
		else if (no_listen[mid] > name)
			return binary_search(low, mid - 1, name);
		else
			return binary_search(mid + 1, high, name);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	int n, m;
	cin >> n >> m;
	//듣도 못한 사람 입력받음.
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		no_listen.push_back(s);
	}
	//이진탐색을 위해서 정렬
	sort(no_listen.begin(), no_listen.end());
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (binary_search(0, (int)no_listen.size() - 1, s))
			result.push_back(s);
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	

	return 0;
}