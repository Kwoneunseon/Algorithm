//2020.09.03
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int *students = new int[n];
	for (int i = 0; i < n; i++)
	{
		students[i] = 1;
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		students[reserve[i] - 1]++;
	}
	for (int i = 0; i < lost.size(); i++)
	{
		students[lost[i] - 1]--;
	}
	for (int i = 0; i < n; i++)
	{
		if (students[i] >= 1) {
			answer++;
		}
		else if (students[i] == 0) {
			if (i >= 1 && students[i - 1] == 2) {
				students[i - 1]--;
				students[i]++;
				answer++;
			}
			else if (i < n - 1 && students[i + 1] == 2) {
				students[i + 1]--;
				students[i]++;
				answer++;
			}
		}
	}

	return answer;
}

int main() {
	int n;
	vector<int> lost;
	vector<int> reserve;
	n = 3;
	lost.push_back(3);
	//lost.push_back(4);
	//reserve.push_back(1);
	reserve.push_back(1);
	//reserve.push_back(5);
	cout << solution(n, lost, reserve);


	return 0;
}