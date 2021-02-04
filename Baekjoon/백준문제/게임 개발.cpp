//1516
//dp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 502
using namespace std;

int N;
int inDegree[MAX], Build_time[MAX];
int result[MAX];
vector<int>need[MAX];

int main() {

	cin >> N;
	for (int i =1; i <= N; i++)
	{
		cin >> Build_time[i];
		while (true) {
			int need_building;
			cin >> need_building;
			if (need_building == -1)break;
			need[need_building].push_back(i);
			inDegree[i]++;
		}
	}

	queue<int>q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0) {
			q.push(i);
			result[i] = Build_time[i];
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < need[x].size(); i++)
		{
			int y = need[x][i];
			inDegree[y]--;

			result[y] = max(result[y], result[x] + Build_time[y]);
			if (inDegree[y] == 0)q.push(y);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << "\n";
	}


	return 0;
}
/*
¹Ý·Ê
5
10 -1
10 1 4 5 -1
4 1 -1
4 3 1 -1
3 3 -1
*/