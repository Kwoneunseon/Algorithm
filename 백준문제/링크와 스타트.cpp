#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int chart[21][21];
	int n,answer=10000000000;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> chart[i][j];
		}
	}
	int a_sum, b_sum;
	for (int i = 1; i < n; i++)
	{
		vector<int>v;
		for (int j = 1; j <= i; j++)
		{
			v.push_back(0);
		}
		for (int j = i+1; j <= n; j++)
		{
			v.push_back(1);
		}

		do {
			a_sum = 0,b_sum=0;
			vector<int> a, b;

			for (int j = 0; j <n ;j++)
			{
				if (v[j] == 0) {
					a.push_back(j);
				}
				else {
					b.push_back(j);
				}
			}

			for (int j = 0; j < a.size(); j++)
			{
				for (int k = j+1; k < a.size(); k++)
				{
					a_sum += (chart[a[j]][a[k]] + chart[a[k]][a[j]]);
				}
			}
			for (int j = 0; j < b.size(); j++)
			{
				for (int k= j+1; k < b.size(); k++)
				{
					b_sum += (chart[b[j]][b[k]] + chart[b[k]][b[j]]);
				}
			}
			answer = min(answer, abs(a_sum - b_sum));


		} while (next_permutation(v.begin(), v.end()));


	}
	cout << answer;

	

	return 0;
}