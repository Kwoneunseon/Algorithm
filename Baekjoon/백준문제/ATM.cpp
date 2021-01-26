//11399번
//그리디 문제
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int people , temp,min_time =0 ;
	cin >> people;
	int *times = new int[people];
	for (int i = 0; i < people; i++)
	{
		cin >> temp;
		times[i] = temp;
	}
	sort(times, times + people);
	for (int i = 0; i <people; i++)
	{
		min_time += times[i] * (people - i);
	}
	cout << min_time;
	return 0;
}