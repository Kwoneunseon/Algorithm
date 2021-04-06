#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k,answer ;
	cin >> n >> k;
	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			q.push(i* j);
		}
	}
	for (int i = 0; i < k-1; i++)
	{
		q.pop();
	}
	cout << q.top();

	return 0;
}