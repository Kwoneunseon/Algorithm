//1789 => 2021.03.10
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 4294967295

using namespace std;

int main() {
	int count = 0;
	long long S, sum =0;
	cin >> S;
	for (int i = 1 ;sum <= S ; i++)
	{
		count++;
		sum += i;
	}
	cout << count-1;

	return 0;
}