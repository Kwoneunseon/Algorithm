#include <iostream>
using namespace std;

int min(int a, int b) {
	return (a > b ? b : a);
}
int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(w - x, h - y), min(x, y));
	system("pause");
	return 0;
}