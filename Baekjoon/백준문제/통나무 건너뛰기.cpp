//11497
//±×¸®µð
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int Testcase;
	cin >> Testcase;
	while (Testcase--) {
		int n, t_height,min_dif=0, dif;
		vector<int>trees;
		cin >> n;
		int *sorted = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> t_height;
			trees.push_back(t_height);
		}

		sort(trees.begin(), trees.end());
		int first = 0, last = n - 1;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)sorted[first++] = trees[i];
			else
				sorted[last--] = trees[i];
		}
		for (int i = 1; i < n; i++)
		{
			if (i == n - 1)
				dif =abs( sorted[n - 1] - sorted[0]);
			else {
				dif = abs(sorted[i] - sorted[i + 1]);
			}
			if (min_dif < dif) {
				min_dif = dif;
			}
		}
		cout << min_dif<<"\n";
	}

	return 0;
}