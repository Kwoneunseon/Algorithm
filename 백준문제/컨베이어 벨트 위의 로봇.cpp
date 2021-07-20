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

	con[0].first--;
	con[0].second = true;
	if (con[0].first == 0)
		zeros++;

	pair<int, bool> temp1, temp2;
	while (zeros != k) {
		//컨테이너를 먼저 옮긴다.
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
			}
		}
		//상자 올리기
		if (con[0].first != 0) {
			con[0].first--;
			con[0].second = true;
			if (con[0].first == 0)
				zeros++;
		}
		for (int i = n-1; i >= 1; i--)
		{
			if (i == n-1) { //박스 내리는 위치
				con[i + 1].second = false;
			}
			else if(con[i].second == true) {
				//옆 칸에 로봇이 있는지 확인하고 내구도 1이상일 때 움직이게 한다.
				if (con[i + 1 ].second == false && con[i + 1].first != 0) {
					con[i].second = false;
					con[i + 1].second = true;
					con[i + 1].first--;
					if (con[i + 1].first == 0)
						zeros++;
					i++;
				}
			}
		}
		cnt++;

	}
	cout << cnt;

	return 0;
}