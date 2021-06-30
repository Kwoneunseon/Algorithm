#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> A(10), B(10);
	int cnt_a = 0, cnt_b = 0;
	for (int i = 0; i < 20; i++)
	{
		if (i / 10 == 0) {
			cin >> A[i % 10];
		}
		else
			cin >> B[i % 10];
	}
	for (int i = 0; i < 10; i++)
	{
		if (A[i] < B[i])
			cnt_b++;
		else if (A[i] > B[i])
			cnt_a++;
		else {
			cnt_b++;
			cnt_a++;
		}
	}
	if (cnt_a > cnt_b)
		cout << "A";
	else if (cnt_a < cnt_b)
		cout << "B";
	else
		cout << "D";

	return 0;
}