#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int value;
	int idx;
};

vector<int> v;
vector<Node> not_re;
vector<int>answer;
int binary_search(int start,int last,int find) {
	if (start > last)
		return -1;
	int mid = (start + last) / 2;
	if (not_re[mid].value < find) {
		start = mid + 1;
		return binary_search(start, last, find);
	}
	else if (not_re[mid].value > find) {
		last = mid - 1;
		return binary_search(start, last, find);
	}
	
	return not_re[mid].idx;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, temp, command;
	cin >> n >> m;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	not_re.push_back({ v[0],0 });
	int pre = v[0];
	for (int i = 1; i < n; i++)
	{
		//첫번째로 나오는 수의 인덱스만 저장한다.
		if (pre != v[i]) {
			pre = v[i];
			not_re.push_back({ pre,i });
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> command;
		cout << binary_search(0,not_re.size()-1,command) << "\n";
	}


	return 0;
}