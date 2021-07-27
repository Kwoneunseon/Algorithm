#include <iostream>

using namespace std;

int fibo(int num) {
	if (num == 0 || num == 1)
		return num;
	return fibo(num - 1) + fibo(num - 2);
}

int main() {
	int n;
	cin >> n;
	cout << fibo(n);
	return 0;
}