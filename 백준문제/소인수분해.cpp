#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, div = 2;
	cin >> N;
	vector<int> primes;
	while (N != 1) {
		if (N%div == 0) {
			primes.push_back(div);
			N /= div;
		}
		else
			div++;
	}
	
	for (int i = 0; i < primes.size(); i++)
	{
		cout << primes[i]<<"\n";

	}

	return 0;
}