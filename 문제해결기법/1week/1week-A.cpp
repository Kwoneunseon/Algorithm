#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int cal[4][1000] = { 0 }, totalHamingDist = 0;
		int m, n;//m : 종의 수 , n : DNA길이
		string change = "ACGT";
		cin >> m >> n;
		string *arr = new string[m];
		for (int i = 0; i < m; i++)
		{
			cin >> arr[i];
		}
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (arr[j][i] == 'A') {
					cal[0][i] = cal[0][i] + 1;
				}
				else if (arr[j][i] == 'C') {
					cal[1][i] = cal[1][i] + 1;
				}
				else if (arr[j][i] == 'G') {
					cal[2][i] = cal[2][i] + 1;
				}
				else if (arr[j][i] == 'T') {
					cal[3][i] = cal[3][i] + 1;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			int max = -1, maxID = -1;
			for (j = 0; j < 4; j++)
			{
				if (max < cal[j][i])
					max = cal[j][i], maxID = j;
			}
			totalHamingDist = totalHamingDist + (m - max);
			cout << change[maxID];
		}
		cout << "\n" << totalHamingDist << "\n";
	}
	return 0;
}
