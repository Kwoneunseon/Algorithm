#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m,first, last, answer = 0,check;
	cin >> n >> m;
	int*rooms = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		rooms[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> first >> last;
		check = rooms[first];
		for (int j = first; j <= last; j++)
		{
			rooms[j] = check;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (rooms[i] == i)
			answer++;
	}
	cout << answer;

	return 0;
}