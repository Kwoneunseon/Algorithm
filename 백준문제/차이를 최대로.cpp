#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int cal(vector<int> v, int n) {
	int sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		sum += (abs(v[i] - v[i + 1]));		
	}
	return sum;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,temp,max_answer=-1;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	do {
		max_answer = max(max_answer, cal(v, n));

	} while (next_permutation(v.begin(), v.end()));

	cout << max_answer;

	return 0;
}