//2805¹ø

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int>trees;
	int size, height;
	cin >> size >> height;
	for (int i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		trees.push_back(temp);
	}

	sort(trees.begin(), trees.end());
	int answer = size - 2, sum = 0, diff;
	for (int i = size - 2; i >= 0; i--)
	{
		answer = trees[i];
		diff = (trees[i + 1] - trees[i])*(size - i - 1);
		if (sum + diff == height) {
			break;
		}
		else if (sum +diff > height) {
			answer += (height - sum);
			break;
		}
		sum += diff;
	}
	cout << answer;


	return 0;
}