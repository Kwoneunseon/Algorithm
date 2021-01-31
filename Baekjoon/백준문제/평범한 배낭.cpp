//12865
//dp - knapsack
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int bags, max_weight,weight,value;
	int dp[102][100000] = { 0, };
	cin >> bags >> max_weight;
	pair<int, int>*item = new  pair<int,int>[bags];
	for (int i = 1; i <= bags; i++)
	{
		cin >> weight >> value;
		item[i] = make_pair(weight, value);
	}

	for (int i = 1; i <= bags; i++)
	{
		for (int j = 0; j <= max_weight; j++)
		{
			if (j >= item[i].first) {
				dp[i][j] = max(dp[i - 1][j - item[i].first] + item[i].second, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[bags][max_weight];


	return 0;
}

/*
 4 6
 2 2
 1 3
 2 1
 3 2

*/