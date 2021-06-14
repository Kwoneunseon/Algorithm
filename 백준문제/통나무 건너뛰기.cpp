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
		int n, t_height,max_dif=0;
		vector<int>trees;
		cin >> n;
		int *sorted = new int[n+1];
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
		sorted[n] = sorted[0];
		for (int i = 0; i < n; i++)
		{
			max_dif = max(max_dif, abs(sorted[i] - sorted[i + 1]));
		}
		cout << max_dif<<"\n";
	}

	return 0;
}