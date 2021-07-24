#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		vector<int>v(3);
		cin >> v[0] >> v[1] >> v[2];
		if (v[0] == 0 && v[1] == 0 && v[2] == 0)
			break;
		sort(v.begin(), v.end());
		for (int i = 0; i < 3; i++)
		{
			v[i] = v[i] * v[i];
		}
		if (v[2] == (v[0] + v[1]))
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";

	}

	return 0;
}