﻿#include <vector>
using namespace std;

vector<int> solution(vector<int>progresses, vector<int> speeds) {
	vector<int>answer; 
	vector<int>check;
	for (int i = 0; i < progresses.size(); i++)
	{
		int remain = (100 - progresses[i]) % speeds[i];
		if (remain == 0) {
			check.push_back((100 - progresses[i]) / speeds[i]);
		}
		else {
			check.push_back((100 - progresses[i]) / speeds[i] + 1);
		}
	}
	int sum = 1;
	int min = check[0];
	for (int i = 1; i < check.size(); i++)
	{
		if (min >= check[i]) {
			sum++;
		}
		else {
			answer.push_back(sum);
			sum = 1, min = check[i];
		}
		if (i == check.size() - 1) {
			answer.push_back(sum);
		}
	}


	return answer;
}

//다른사람 코드
vector<int> solution_1(vector<int>progress, vector<int> speeds) {
	vector<int> answer;

	int day, max_day = 0;
	for (int i = 0; i < progress.size(); i++)
	{
		//나머지가 있을 경우 +1을 해주는 간단한 식
		day = (99 - progress[i]) / speeds[i] + 1;

		if (answer.empty() || max_day < day) {
			answer.push_back(1);
		}
		else {
			++answer.back();
		}

		if (max_day < day) {
			max_day = day;
		}
	}
	return answer;
}