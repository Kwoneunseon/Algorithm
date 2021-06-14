//2562
//for¹®»ç¿ë
#include <iostream>
using namespace std;

int main() {
	int max = 0, max_idx,temp;
	for (int i = 1; i <= 9; i++)
	{
		cin >> temp;
		if (temp > max) {
			max = temp;
			max_idx = i;
		}	
	}
	cout << max<<"\n"<<max_idx;

	return 0;
}