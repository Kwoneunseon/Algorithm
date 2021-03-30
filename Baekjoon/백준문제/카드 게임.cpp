#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T,n;
	cin >> T;
	while (T--) {
		cin >> n;
		int * arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int x=0, y=n-1,idx=0,answer=0,temp;
		while (x <= y) {
			if (arr[x] >= arr[y]) {
				temp = arr[x];
				x += 1;
			}
			else {
				temp = arr[y];
				y -= 1;
			}
			if (idx % 2 == 0) {
				answer += temp;
			}
			idx++;

		}
		cout << answer<<"\n";
	}


	return 0;
}