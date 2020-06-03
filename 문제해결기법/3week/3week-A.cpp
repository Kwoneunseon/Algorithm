#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int rount = 0;
		int n;//n은 원반의 개수
		cin >> n;
		int disc[10000] = { 0, };
		for (int i = 1; i <= n; i++)
		{
			cin >> disc[i];
		}
		int target = n;
		while (true) {
			rount++;
			for (int i = 1; i <= n; i++)
			{
				if (disc[i] == target) {
					target--, disc[i] = 0;
				}
				if (target == 0) {
					break;
				}
			}
			if (target == 0) {
				break;
			}
		}
		cout << rount << "\n";
	}
	return 0;
}