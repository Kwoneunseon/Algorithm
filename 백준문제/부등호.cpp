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
	vector<int> num(10);
	vector<char> inequality;
	char temp;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		inequality.push_back(temp);
	}
	for (int i = 9; i >=0 ; i--)
	{
		num[9-i] = i;
	}

	
	do {
		if (check(num, inequality)) break;
	} while (prev_permutation(num.begin(), num.end()));

	for (int i = 0; i <= k; i++)
	{
		cout << num[i];
	}

	cout << "\n";
	sort(num.begin(), num.end());

	do {
		if (check(num, inequality))break;
	} while (next_permutation(num.begin(), num.end()));

	for (int i = 0; i <= k; i++)
	{
		cout << num[i];
	}
	
	return 0;
}