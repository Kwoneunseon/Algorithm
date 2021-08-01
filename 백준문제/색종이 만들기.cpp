#include <iostream>
#include <vector>

using namespace std;

int map[128][128] = { 0, };
int blue = 0, white = 0;

void find(int x, int y, int size) {
	if (size == 0)
		return;
	bool flag = false;
	for (int i = x; i < x+size; i++)
	{
		for (int j = y; j < y+ size; j++)
		{
			if (map[i][j] == 0) {
				flag = true;
				break;
			}
		}
	}
	if (flag) {
		find(x, y, size / 2);
		find(x + size/2, y, size / 2);
		find(x , y + size / 2, size / 2);
		find(x + size / 2, y + size / 2, size / 2);
	}
	else {
		blue++;
		white += size * 2 - 1;
	}


}

int main() {
	int N; 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	find(0, 0, N);
	cout << white << "\n" << blue;


	return 0;
}