#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>arr[100];
int n;
int root[100][100];

void bfs(int x) {
	queue<int>q;
	int cnt = 0;
	int c[100] = { 0, };
	q.push(x);
	while (!q.empty()) {
		int key = q.front();
		
		q.pop();
		for (int i = 0; i < arr[key].size(); i++)
		{
			int y = arr[key][i];
			if (c[y] != true) {
				c[y] = true;
				q.push(y);
			}
			if (y == x) {
				cnt = 1;
			}
		}
		root[x][key] = 1;
		
	}
	if (cnt == 1) {
		root[x][x] = 1;
	}
	else {
		root[x][x] = 0;
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if (temp == 1) {
				arr[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		bfs(i);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << root[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}