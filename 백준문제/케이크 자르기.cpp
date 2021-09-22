#include <iostream>
#include <vector>

using namespace std;

bool cake_count(vector<int> v, int size, int standard) {
	int sum_now = 0, count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum_now += v[i];
		if (sum_now >= standard) {
			count++;
			sum_now = 0;
		}
	}
	return count > size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cake_length,q;
	cin >> n >> m >> cake_length;
	vector<int> cake;
	int first=0, last;
	for (int i = 0; i < m; i++)
	{
		cin >> last;
		cake.push_back(last - first);
		first = last;
	}
	cake.push_back(cake_length - first);

	while(n--) 
	{
		cin >> q;
		first = 1, last = cake_length;
		while (first +1 < last) {
			int mid = (first + last) / 2;
			if (cake_count(cake, q, mid))first = mid;
			else last = mid;
		}

		cout << first<<"\n";

	}



	return 0;
}