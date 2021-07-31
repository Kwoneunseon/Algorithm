#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int,int>> a,pair<int, pair<int, int>> b) {
	if (a.first == b.first)
		return a.second.first < b.second.first;
	else
		return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,first,last,dif,answer= 0,max=-1;
	cin >> n;
	vector < pair<int, pair<int, int> >>schedule;

	for (int i = 0; i < n; i++)
	{
		cin >> first >> last;
		dif = last - first;
		if (last > max)
			max = last;
		schedule.push_back({ dif,{first,last} });
	}
	vector<int> time(max + 1);
	sort(schedule.begin(), schedule.end(),compare);
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		check = false;
		for (int j = schedule[i].second.first+1; j <= schedule[i].second.second; j++)
		{
			if (time[j] != 0) {
				check = true;
				break;
			}
		}
		if (check)
			continue;
		else {
			answer++;
			for (int j = schedule[i].second.first; j <= schedule[i].second.second; j++)
			{
				time[j] = 1;
			}
		}
	}

	cout << answer;
	return 0;
}