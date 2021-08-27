#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt = 0;

void back_tracking(vector<int> v, int sum) {
	if (sum > n)
		return;
	if (sum == n) {
		cnt++;
		if (cnt == k) {
			int v_size = v.size();
			for (int i = 0; i < v_size; i++)
			{
				if (i == v_size - 1)
					cout << v[i];
				else
					cout << v[i] << "+";
			}
			return;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		v.push_back(i);
		back_tracking(v, sum+i);
		v.pop_back();
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	vector<int> v;
	back_tracking(v, 0);

	if (cnt < k)cout << -1;

	return 0;
}