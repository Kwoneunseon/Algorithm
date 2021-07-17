#include <iostream>
#include <vector>

using namespace std;

int main() {
	int idx = 0, cnt = -1; //cnt가 -1인 이유는 처음에 공을 주는것을 카운트하지 않기 위해서
	int n, m, l;//m이 끝나는 시점, l이 움직이는 크기
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