#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//binary search

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> no_listen(n), no_see(m),answer;
	for (int i = 0; i < n; i++)
	{
		cin >> no_listen[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> no_see[i];
	}
	sort(no_listen.begin(), no_listen.end());
	sort(no_see.begin(), no_see.end());
	int i = 0, j = 0,flag= 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (no_listen[j] == no_see[i]) {
				answer.push_back(no_see[i]);
				break;
			}
		}
	}
	cout << answer.size()<<"\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i]<<"\n";
	}

	

	return 0;
}