#include <iostream>
#include <vector>
#include <algorithm>
//
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int *w = new int[n];
		int *v = new int[n];
		int *copy = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			copy[i] = w[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int max = 0;
	
		sort(copy, copy + n);
		do {
			int sum = 0, ans = 0;
			for (int i = 0; i < n;i++) {
				if (sum + copy[i] <= k) {
					sum += copy[i];
					for (int j = 0; j < n; j++)
					{
						if (copy[i] == w[j]) {
							ans += v[j];
							break;
						}
					}
				}
				else if (sum + copy[i] > k)
					break;
			}
			if (ans > max) {
				max = ans;
			}
		} while (next_permutation(copy, copy + n));

		cout << max << endl;
			

	}
	return 0;
}
