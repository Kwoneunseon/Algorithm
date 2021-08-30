#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>v;
//parameter에 vector가 들어가면 시간초과가 뜸.
bool binary_search(int start, int end,int key) {
	if (start > end) return false;

	int mid = (start + end) / 2;

	if (v[mid] == key)
		return true;
	else if (v[mid] > key)
		return binary_search(start, mid - 1, key);
	else
		return binary_search(mid + 1, end, key);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,temp;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int T,key;
	cin >> T;
	while (T--) {
		cin >> key;
		cout << binary_search(0, n - 1, key)<<"\n";
	}
	return 0;
}