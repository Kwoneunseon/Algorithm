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
	//ó�� ���ڸ� �ø� ��.

	pair<int, bool> temp1, temp2;
	while (true) {
		//�����̳ʸ� ���� �ű��.
		cnt++;
		temp1 = con[0];
		for (int i = 1; i < 2 * n; i++)
		{
			if (i + 1 == 2 * n) {
				temp2 = con[i];
				con[i] = temp1;
				con[0] = temp2; //������

			}
			else {
				temp2 = con[i];
				con[i] = temp1;
				temp1 = temp2;
				if (i == n - 1) {
					con[i].second = false;//�ڽ��� �����ش�.
				}
			}
		}
		for (int i = n-2; i >= 0 ; i--)
		{
			if(con[i].second == true) {
				//�� ĭ�� �κ��� �ִ��� Ȯ���ϰ� ������ 1�̻��� �� �����̰� �Ѵ�.
				if (con[i + 1].second == false && con[i + 1].first > 0) {
					con[i].second = false;
					con[i + 1].second = true;
					con[i + 1].first--;
					if (con[i+1].first == 0)
						zeros++;
				}
			}
		}
		if (con[n - 1].second)con[n - 1].second = false;//�����ش�.
		//���� �ø���
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