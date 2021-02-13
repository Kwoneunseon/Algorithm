//1546
//for
#include <iostream>
using namespace std;

int main() {
	int n,max=0,temp;
	double answer=0;
	cin >> n;
	double *score = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp > max)
			max = temp;
		score[i] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		score[i] = ((double)score[i] / max) * 100;
		answer += score[i];
	}

	cout << answer/(double)n;
	return 0;
}