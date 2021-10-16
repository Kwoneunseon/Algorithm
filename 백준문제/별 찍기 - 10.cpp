#include <algorithm>
#include <iostream>

using namespace std;

char mat[2201][2201];

int solve(int y, int x, int num) {
	if (num == 1) {
		mat[x][y] = '*';
		return;
	}

	int div = num / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				;
			else
				solve(y + (i*div), x + (j*div), div);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	solve(0, 0, n);
	memset(mat, ' ', sizeof(mat));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j];
		}
		cout << "\n";
	}

	return 0;
}