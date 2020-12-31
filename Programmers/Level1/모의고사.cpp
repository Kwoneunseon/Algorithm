#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//점수로만 비교를 하기 위해서
bool cmp(pair<int,int> a, pair<int, int> b) {
	return a.first > b.first;
}


int std1[] = { 1,2,3,4,5 };
int std2[] = { 2,1,2,3,2,4,2,5 };
int std3[] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector< pair<int,int> > std_score;

	int std1_score = 0, std2_score = 0, std3_score = 0;
	for (int i = 0; i < answers.size(); i++)
	{
		if (std1[i % 5] == answers[i]) {
			std1_score += 1;
		}
		if (std2[i % 8] == answers[i]) {
			std2_score += 1;
		}
		if (std3[i % 10] == answers[i]) {
			std3_score += 1;
		}
	}

	std_score.push_back(make_pair(std1_score, 0));
	std_score.push_back(make_pair(std2_score, 1));
	std_score.push_back(make_pair(std3_score, 2));

	sort(std_score.begin(), std_score.end(),cmp);

	for (int i = 0; i < 3; i++)
	{
		answer.push_back(std_score[i].second+1);
		if (i+1 <3 && std_score[i].first == std_score[i + 1].first ) {
			continue;
		}
		break;
	}
	

	return answer;
}

vector<int>other_solution(vector<int> answers) {
	vector<int>answer;
	vector<int> they(3);

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == std1[i % 5]) they[0]++;
		if (answers[i] == std2[i % 8]) they[1]++;
		if (answers[i] == std3[i % 10]) they[2]++;
	}

	int max = *max_element(they.begin(), they.end());
	for (int i = 0; i < 3; i++) {
		if (they[i] == max)answer.push_back(i + 1);
	}
	return answer;
}

int main() {
	vector<int> a = { 1,3,2,4,2 };
	vector<int> k = solution(a);
	for (int i = 0; i < k.size(); i++)
	{
		cout << k[i] << endl;
	}

	return 0;
}