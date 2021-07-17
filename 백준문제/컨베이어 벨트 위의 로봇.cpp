#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	int zeros = 0, cnt = 0;
	cin >> n >> k;
	vector<pair<int,bool> >con(2 * n);
	for (int i = 0; i < 2*n; i++)
	{
		cin >> con[i].first;
		con[i].second = false;
	}
	con[0].first--;con[0].second = true;//처음 상자올리기
	pair<int, bool> temp1,temp2;
	while (zeros != k) {
		//컨테이너를 먼저 옮긴다.
		temp1 = con[0];
		for (int i =1; i < 2*n; i++)
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
		//상자 
		if (con[0].first != 0) {
			con[0].first--;
			if (con[0].first == 0)
				zeros++;
			con[0].second = true;
		}
		for (int i = 1; i < 2*n; i++)
		{
			if (con[i].second = true) {
				if (con[(i + 1)%(2*n)].second == false && con[(i + 1) % (2 * n)].first > 0) {
					con[(i + 1) % (2 * n)].second = true;
					con[(i + 1) % (2 * n)].first--;
					if (con[(i + 1) % (2 * n)].first == 0)
						zeros++;
				}
			}
			if (i == n) {
				con[i + 1].second = false;
			}
		}
		cnt++;

	}

	return 0;
}