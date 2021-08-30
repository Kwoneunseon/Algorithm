#include <iostream>

using namespace std;

int map[1026][1026] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col,temp,T,sum;
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
	{
		sum = 0;
		for (int j= 1; j <= col; j++)
		{
			cin >> temp;
			sum += temp;
			map[i][j] = map[i - 1][j] + sum;
		}
	}
	cin >> T;
	int x1, y1, x2, y2,answer;
	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2;
	
		answer = map[x2][y2] - map[x1 - 1][y2] - map[x2][y1 - 1]+map[x1-1][y1-1];
		cout << answer << "\n";
	}

	



	return 0;
}