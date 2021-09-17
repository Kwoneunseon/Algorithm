#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> v, vector<char>inequality) {
	for (int i = 0; i < inequality.size(); i++)
	{
		if (inequality[i] == '<' && (v[i] >= v[i + 1])) return false;
		if (inequality[i] == '>' && (v[i] <= v[i + 1])) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	vector<int> small(10), big(10);
	vector<char> inequality;
	char temp;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		inequality.push_back(temp);
	}
	for (int i = 0; i <= 9; i++)
	{
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (check(small, inequality)) break;
	} while (next_permutation(small.begin(), small.end()));


	do {
		if (check(big, inequality))break;
	} while (next_permutation(big.rbegin(), big.rend()));

	for (int i = 0; i <= k; i++)
	{
		cout << big[i];
	}
	cout << "\n";
	for (int i = 0; i <= k; i++)
	{
		cout << small[i];
	}
	
	return 0;
}