#include <iostream>

using namespace std;

int main() {
	int size,temp;
	int min = 1000000, max = -1000000;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		if (min > temp) {
			min = temp;
		} 
		if (max < temp) {
			max = temp;
		}
	}
	cout << min << " "<<max;

	return 0;
}