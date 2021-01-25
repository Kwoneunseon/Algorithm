#include <iostream>
using namespace std;

int main() {
	int T, N, temp, sum = 0;
	cin >> T;
	for (int i = 0; i <T; i++)
	{
		cin >> N;
		sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			sum += temp;
		}
		cout << sum<<"\n";
	}

	return 0;
}