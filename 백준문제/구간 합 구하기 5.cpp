#include <iostream>
using namespace std;

using namespace std;

int table[1025][1025];
int sum[1025][1025] = { 0, };

int main() {
	int n, m, x1, x2, y1, y2, side;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		side = 0;
		for (int j = 1; j <= n; j++)
		{
			cin >> table[i][j];

			sum[i][j] = sum[i - 1][j] + table[i][j] + side;
			side += table[i][j];
		}
	}
	while (m--) {

		int answer = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2 ][y1-1] + sum[x1 - 1][y1 - 1];

		cout << answer<< "\n";
	}

	return 0;
}