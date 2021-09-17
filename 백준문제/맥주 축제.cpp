#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Beer {
	int v, c;
};

bool cmp(const Beer &b1, const Beer &b2) {
	if (b1.c < b2.c)
		true;
	else if (b1.c == b2.c)
		return b1.v > b2.v;
	else
		return false;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, k,sum = 0,answer =-1;
	cin >> n >> m >> k;
	vector<Beer> b;
	for (int i = 0; i < k; i++)
	{
		Beer beer;
		cin >> beer.v >> beer.c;
		b.push_back(beer);
	}
	sort(b.begin(), b.end(), cmp);
	vector<int> check;
	for (int i = 0; i < k; i++)
	{
		check.push_back(b[i].v);
		sum += b[i].v;
	
		if (check.size() == n) {
			if (sum >= m) {
				answer = b[i].c;
				break;
			}
			else {
				sum -= b[i].v;
				check.pop_back();
			}
		}

	}
	if (answer != -1)
		cout << answer;
	else
		cout << "-1";

	return 0;
}