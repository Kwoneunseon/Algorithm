#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int k,answer= 0;
		cin >> k;
		vector<int>v(k);
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		while (v.size()!=1) {
			if (v.size() == 2) {
				answer += (v[0] + v[1]);
				break;
			}
			vector<int>temp;
			temp.push_back(v[0]);

			for (int i = 1; i < v.size()-1; i++)
			{
				if (temp[temp.size()-1] <= v[i + 1]) {
					temp[temp.size() - 1] += v[i];
					answer += (temp[temp.size() - 1]);
					if (i == v.size() - 2) {
						temp.push_back(v[i + 1]);
						answer += v[i + 1];
					}
				}
				else {
					temp.push_back(v[i] + v[i + 1]);
					i++;
					answer += (temp[temp.size() - 1]);
				}
			}
			v = temp;
		}

		cout << answer << "\n";

	}


	return 0;
}