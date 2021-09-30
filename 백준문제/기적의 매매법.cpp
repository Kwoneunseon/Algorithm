#include <iostream>

using namespace std;
int money;
int stock[14];

int BNP() {
	int cash = money, cnt=0;//cash 현굼, cnt : 보유 주식 수
	for (int i = 0; i < 14; i++)
	{
		if (cash == 0)
			break;
		cnt += cash / stock[i];
		cash %= stock[i];
	}
	return cash + stock[13] * cnt;
}

int Timing() {
	int cash = money, cnt = 0, minus = 0, plus = 0;
	for (int i = 1; i < 14; i++)
	{
		if (stock[i] < stock[i - 1]) {
			minus++;plus = 0;
		}
		else if (stock[i] > stock[i - 1]){
			plus++; minus = 0;
		}
		else {
			minus = 0;plus = 0;
		}
		if (minus >= 3) {
			cnt += cash / stock[i];
			cash %= stock[i];
		}
		else if (plus >= 3) {
			cash += stock[i] * cnt;
			cnt = 0;
			plus = 0;
		}
	}
	return cash + stock[13] * cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> money;
	for (int i = 0; i < 14; i++)
	{
		cin >> stock[i];
	}
	if (BNP() > Timing())
		cout << "BNP";
	else if (BNP() < Timing())
		cout << "TIMING";
	else
		cout << "SAMESAME";

	return 0;
}