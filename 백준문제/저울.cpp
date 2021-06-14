//2437
//그리디
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, temp;
	vector<int> weight;
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		cin >> temp;
		weight.push_back(temp);
	}
	int answer = 1; //구한 값에  +1를 해줘야 하기때문.
	sort(weight.begin(), weight.end());
	for (int i = 0; i < n; i++)
	{
		if (weight[i] > answer)
			break;
		answer += weight[i];
	}
	cout << answer;

	return 0;
}