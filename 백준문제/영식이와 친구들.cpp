#include <iostream>
#include <vector>

using namespace std;

int main() {
	int idx = 0, cnt = -1; //cnt�� -1�� ������ ó���� ���� �ִ°��� ī��Ʈ���� �ʱ� ���ؼ�
	int n, m, l;//m�� ������ ����, l�� �����̴� ũ��
	cin >> n >> m >> l;
	vector<int>friends(n);
	while (true) {
		friends[idx]++;
		cnt++;
		if (friends[idx] == m) {
			break;
		}
		idx = (idx + l) % n;

	}
	cout << cnt;

	return 0;
}