#include <iostream>
#include <cmath>
typedef long long ll;

using namespace std;

int main() {
	int T;
	cin >> T;
	ll x, y,max=0,remain,answer;
	while (T--) {
		max=0;
		cin >> x >> y;
		while (max*max <= y - x)
			max++;
		max--;
		answer = 2 * max - 1;
 		remain = (y - x) - max * max;
		//���� ū ���� �������� ��� �ʿ����� Ȯ���ؼ� �ʿ��� ������ŭ �÷���.
		remain = (ll)ceil((double)remain /(double)max);
		answer += remain;
		cout << answer << "\n";

	}



	return 0;
}