//10773
//string
#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long k,answer =0;
	cin >> k;
	int temp;
	vector<int> v;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		if (temp == 0) {
			v.erase(v.end()-1, v.end());
		}
		else {
			v.push_back(temp);
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		answer += v[i];
	}
	cout << answer;
	return 0;
}