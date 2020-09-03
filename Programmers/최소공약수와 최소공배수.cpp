//2020.09.03
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int m) {
	vector<int>answer;
	int min, max;
	if (n > m) {
		int temp = m;
		m = n;
		n = temp;
	}
	for (int i = 1; i <= n; i++)
	{
		if (n %i == 0 && m%i == 0) {
			min = i;
		}
	}
	max = (m*n) / min;
	answer.push_back(min);
	answer.push_back(max);


	return answer;
}

int main() {
	vector<int> arr = solution(2,5);
	cout << arr[0] << " " << arr[1] << endl;

	return 0;
}