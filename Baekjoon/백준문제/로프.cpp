//2217번
//그리디 알고리즘


#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int count ,temp, max = 0;
	cin >> count;
	int *ropes = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		ropes[i] = temp;
	}
	sort(ropes, ropes + count);
	for (int i = 0; i < count ; i++)
	{
		if (max < (count - i)*ropes[i]) {
			max = (count - i)*ropes[i];
		}
	}
	cout << max;

	return 0;
}