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

	con[0].first--;
	con[0].second = true;
	if (con[0].first == 0)
		zeros++;

	pair<int, bool> temp1, temp2;
	while (zeros != k) {
		//�����̳ʸ� ���� �ű��.
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
			}
		}
		//���� �ø���
		if (con[0].first != 0) {
			con[0].first--;
			con[0].second = true;
			if (con[0].first == 0)
				zeros++;
		}
		for (int i = n-1; i >= 1; i--)
		{
			if (i == n-1) { //�ڽ� ������ ��ġ
				con[i + 1].second = false;
			}
			else if(con[i].second == true) {
				//�� ĭ�� �κ��� �ִ��� Ȯ���ϰ� ������ 1�̻��� �� �����̰� �Ѵ�.
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