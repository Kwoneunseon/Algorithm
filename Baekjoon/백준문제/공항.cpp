#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int airport[100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int G, P, g, count = 0;
	bool flag = false;
	cin >> G >> P;
	memset(airport, 0, G + 2);
	for (int i = 0; i < P; i++)
	{
		cin >> g;
		flag = false;
		for (int j = g; j >= 1; j--)
		{
			if (airport[j] == 0) {
				airport[j] = 1;
				flag = true;
				count++;
				break;
			}
		}
		if (!flag)
			break;
	}

	cout << count;


	return 0;
}