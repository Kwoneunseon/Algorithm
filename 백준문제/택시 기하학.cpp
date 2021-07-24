#include <iostream>
#define PI 3.14159;

using namespace std;

int main() {
	double R,area1,area2;
	cin >> R;
	area1 =R * R*PI;
	area2 = (2 * R)*R;
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << area1 << "\n" << area2;

	return 0;
}