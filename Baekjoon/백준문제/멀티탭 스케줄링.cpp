//1449
//±×¸®µð
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, length, temp;
	cin >> n >> length;
	int start, answer = 1;
	vector<int> points;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		points.push_back(temp);
	}

	sort(points.begin(), points.end());

	start = points[0];
	for (int i = 1; i < points.size(); i++)
	{
		if (points[i] - start + 1 > length) {
			answer++;
			start = points[i];
		}
	}
	cout << answer;

	return 0;
}