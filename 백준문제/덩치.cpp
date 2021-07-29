#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, rank = 1, weight ,height,count=1;
	cin >> n;
	vector<pair<pair<int, int>,int> > persons(n);
	vector<int>answer(n);
	for (int i = 0; i < n; i++)
	{
		cin >> weight >> height;
		persons[i] = {{weight,height} ,i};
	}
	sort(persons.rbegin(), persons.rend());
	answer[persons[0].second] = rank;
	for (int i = 1; i < n; i++)
	{
		if (persons[i-1].first.second < persons[i].first.second) {
			answer[persons[i].second] = rank;
			count++;
		}
		else {
			rank += count;
			count = 1;
			answer[persons[i].second] = rank;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}