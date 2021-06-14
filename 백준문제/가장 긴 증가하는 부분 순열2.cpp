//12015- 2021.03.10
//Âü°í -https://ferrante.tistory.com/54
#include <iostream>	
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (v.empty() || v.back() < x)
			v.push_back(x);
		else {
			int idx = lower_bound(v.begin(), v.end(), x)-v.begin();
			v[idx] = x;
		}
	}
	cout << v.size();
	return 0;
}