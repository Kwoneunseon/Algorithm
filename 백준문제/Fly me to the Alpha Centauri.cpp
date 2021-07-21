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
		//가장 큰 수를 기준으로 몇개가 필요한지 확인해서 필요한 개수만큼 플러스.
		remain = (ll)ceil((double)remain /(double)max);
		answer += remain;
		cout << answer << "\n";

	}



	return 0;
}