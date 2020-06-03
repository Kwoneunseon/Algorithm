#include <iostream>
#include <algorithm>
using namespace std;

class ball {
public:
	int idx;
	bool direc;
};

bool cmp(const ball&b1, const ball&b2) {
	return b1.idx < b2.idx;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int L, n, temp, k, cnt = 0, clock = 0; //L:길이 n : 개수 k:순서
		cin >> n >> L >> k; //cnt :  떨어진 갯수 clock시간
		ball *arr = new ball[n];
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (temp > 0) {
				arr[i].idx = temp;
				arr[i].direc = true;
			}
			else {
				arr[i].idx = -temp;
				arr[i].direc = false;
			}
		}
		int tmpx = 0, tmpy = 0;
		sort(arr, arr + n, cmp);
		while (cnt != k) {
			clock++;
			for (int i = tmpx ; i < n-tmpy; i++)
			{
				if (arr[i].direc == true) {
					arr[i].idx++;
					if (arr[i].idx == L) {
						cnt++;
						tmpy++;
					}
				}
				else if (arr[i].direc == false) {
					arr[i].idx--;
					if (i > tmpx ) {
						if (arr[i].idx == arr[i - 1].idx) {
							arr[i - 1].direc = false;
							arr[i].direc = true;
						}
						if (arr[i].idx < arr[i-1].idx) {
							arr[i].direc = true;
							arr[i-1].direc = false;
							int temp = arr[i-1].idx;
							arr[i-1].idx = arr[i].idx;
							arr[i].idx = temp;
						}
					}
					if (arr[i].idx == 0) {
						cnt++;
						tmpx++;
					}
				}
			}		
		}
		cout << clock << "\n";
	}
	return 0;
}