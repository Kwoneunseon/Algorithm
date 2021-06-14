//4796
//그리디 알고리즘

#include <iostream>
using namespace std;

int main() {

	int P, L, V,case_cnt=1;//P : 연속 날짜 , L : 사용 날짜 , V : 휴가 날짜
	while (true) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		cout << "Case " << case_cnt << ": ";
		int remain = V % P;
		if (remain > L) {
			cout << (V / P)*L + L << "\n";
		}
		else {
			cout << (V / P)*L + remain << "\n";
		}
		case_cnt++;
	}
	return 0;
}