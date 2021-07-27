#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;
	int x1, y1, r1, x2, y2, r2;
	double distance;
	while (T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//���� �������� r1���� �����Ѵ�
		if (r1 > r2)
			swap(r1, r2);
		distance = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		distance = sqrt(distance);
		if (distance == r1 + r2)
			cout << 1;
		else if (distance < r1 + r2) {
			//�߽��� ���� ��
			if (x1 == x2 && y1 == y2) {
				if (r1 == r2) //������ ��
					cout << -1;
				else //�������� �ٸ����
					cout << 0;
			}
			else {
				if (distance + r1 < r2)
					cout << 0;
				else if (distance + r1 == r2)
					cout << 1;
				else
					cout << 2;
			}
		}			
		else			
			cout << 0;
		cout << "\n";
	}
	return 0;
}