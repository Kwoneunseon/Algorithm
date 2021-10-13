#include <iostream>
using namespace std;

int n;
char map[3100][6200] = {};

void draw(int x, int y) {
	map[x][y] = '*';
	map[x+1][y-1] = '*'; map[x +1][y+1] = '*';
	for (int i = 0; i < 5; i++)
	{
		map[x + 2][y - 2 + i] = '*';
	}		
}

void recursive(int n, int x, int y) {
	if (n == 3) {
		draw(x, y);
		return;
	}
	recursive(n / 2, x, y);
	recursive(n / 2, x + n / 2, y + n / 2);
	recursive(n / 2, x + n / 2, y - n / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2*n; j++)
		{
			map[i][j] = ' ';
		}
	}
	recursive(n, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2*n-1; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}


	return 0;
}