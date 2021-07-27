#include <iostream>

using namespace std;

void star(int i, int j, int n) {
	//박스 중앙 있는 위치는 무조건 비워준다.
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << " ";
	else {
		if ( n / 3 == 0)
			cout << "*";
		else {
			//중앙근처 확인하기 위해서
			star(i, j, n / 3);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			star(i, j, n);
		}
		cout << "\n";
	}


	return 0;
}