#include <iostream>
#include <vector>

using namespace std;

int load[100001] = { 0, };
vector<int> point;

bool check(int height) {
	for (int i = 1; i < point.size(); i++)
	{
		if (i != 1 && i != point.size() - 1) {
			if (height * 2 < point[i])
				return false;
		}
		else {
			if (height < point[i])
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x;

	cin >> N >> M;
	point.push_back(0);
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		point.push_back(x);
	}
	point.push_back(N);

	for (int i = M+1; i >0; i--)
	{
		point[i] = point[i] - point[i - 1];
	}

	int first=0, last=N, mid;
	while (first +1 < last) {
		mid = (first + last) / 2;
		if (check(mid))
			last = mid;
		else
			first = mid;
	}

	cout << last;

	return 0;
}