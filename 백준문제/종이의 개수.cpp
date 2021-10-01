#include <iostream>
using namespace std;

int N;
int paper[2187][2187];
int m_one = 0, zero = 0, one = 0;

void solve(int x, int y, int size) {
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (paper[i][j] != paper[x][y]) {
				for (int a = x; a < x+size; a+=size/3)
				{
					for (int b = y; b < y+size; b +=size/3)
					{
						solve(a, b, size / 3);
					}
				}
				return;
			}
		}
	}
	if (paper[x][y] == 1)
		one++;
	else if (paper[x][y] == 0)
		zero++;
	else if (paper[x][y] == -1)
		m_one++;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}
	solve(0, 0, N);

	cout << m_one << "\n" << zero << "\n" << one;

	return 0;
}