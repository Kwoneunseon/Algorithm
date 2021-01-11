#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int>lost, vector<int>reserve) {
	int answer=0;
	int *student = new int[n];
	fill_n(student, n, 1);
	//잃어버린 경우
	for (int i = 0; i < lost.size(); i++)
	{
		student[lost[i] - 1]--;
	}
	//여벌이 있는 경우
	for (int i = 0; i < reserve.size(); i++)
	{
		student[reserve[i] - 1]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (student[i] < 1) {
			if (student[i - 1] > 1 && i - 1 > 0) {
				answer++;
				student[i - 1]--;
				continue;
			}
			else if (student[i + 1] > 1 && i + 1 < n) {
				answer++;
				student[i + 1]--;
				continue;
			}
		}
		if (student[i] >= 1) {
			answer++;
		}


	}

	return answer;
}
