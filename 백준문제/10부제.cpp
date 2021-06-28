#include <iostream>	
using namespace std;

int main() {
	int n, temp, answer = 0;
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		if (temp == n)
			answer++;
	}
	cout << answer;

	return 0;
}