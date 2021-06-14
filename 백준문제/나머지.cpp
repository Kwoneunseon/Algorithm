//3052
//for
#include <iostream>
using namespace std;

int main() {
	int check[42] = { 0, };
	int numbers[10];
	int answer = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> numbers[i];
		check[numbers[i] % 42]++;
	}
	for (int i = 0; i < 42; i++)
	{
		if (check[i] != 0)
			answer++;
	}

	cout << answer;
	return 0;
}