#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;
	int zeros = 0, cnt = 0;
	cin >> n >> k;
	vector<pair<int, bool> >con(2 * n);
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> con[i].first;
		con[i].second = false;
	}
	//처음 상자를 올릴 때.

	pair<int, bool> temp1, temp2;
	while (true) {
		//컨테이너를 먼저 옮긴다.
		cnt++;
		temp1 = con[0];
		for (int i = 1; i < 2 * n; i++)
		{
			if (i + 1 == 2 * n) {
				temp2 = con[i];
				con[i] = temp1;
				con[0] = temp2; //마지막

			}
			else {
				temp2 = con[i];
				con[i] = temp1;
				temp1 = temp2;
				if (i == n - 1) {
					con[i].second = false;//박스를 내려준다.
				}
			}
		}
		for (int i = n-2; i >= 0 ; i--)
		{
			if(con[i].second == true) {
				//옆 칸에 로봇이 있는지 확인하고 내구도 1이상일 때 움직이게 한다.
				if (con[i + 1].second == false && con[i + 1].first > 0) {
					con[i].second = false;
					con[i + 1].second = true;
					con[i + 1].first--;
					if (con[i+1].first == 0)
						zeros++;
				}
			}
		}
		if (con[n - 1].second)con[n - 1].second = false;//내려준다.
		//상자 올리기
		if (con[0].first > 0 && con[0].second == false) {
			con[0].first--;
			con[0].second = true;
			if (con[0].first == 0)
				zeros++;
		}

		if (zeros >= k)
			break;

	}
	cout << cnt;

 	return 0;
}