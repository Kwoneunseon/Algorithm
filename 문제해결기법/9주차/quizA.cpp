#include <iostream>
#include <algorithm>
using namespace std;
bool desc(int a, int b) {
	return a > b;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		int check[10001] = { 0 };
		cin >> n >> k;
		int *w = new int[n];
		int *v = new int[n];
		int *copy = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			copy[i] = v[i] / w[i];
		}
		sort(copy, copy + n, desc);
		int sum = 0, ans = 0;
		bool end = false;
	
	


		for (int i = 0; i < n; i++)
		{
			for (int j = 0;j < n;j++) {
				if (copy[i] == v[j] /w[j]) {
					if (sum + w[j] <= k && check[j]==0) {
						check[j] = 1;
						sum += w[j];
						ans += v[j];
						break;
					}
					else if(check[j]==0) {
						int temp = k - sum;
						ans += v[j] / w[j] * temp;
						end = true;
						break;
					}
				}
			}
			if (end)
				break;
		}
		cout << ans<<endl;
	}
	return 0;

}