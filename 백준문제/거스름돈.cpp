//5585번
// 거스름돈
//그리디 알고리즘

#include <iostream>
using namespace std;

int money[] = { 500,100,50,10,5,1 };

int main() {
	int change, cnt = 0,idx= 0;
	cin >> change;
	change = 1000 - change;
	while (change != 0) {
		cnt += change / money[idx];
		change = change % money[idx];
		idx++;
	}
	cout << cnt;

	return 0;
}