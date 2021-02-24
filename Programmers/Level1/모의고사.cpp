//2021.02.25
//º¹½À
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int student1[] = { 1,2,3,4,5 };
	int student2[] = { 2,1,2,3,2,4,2,5 };
	int student3[] = { 3,3,1,1,2,2,4,4,5,5 };
	int cnt[3] = { 0, };
	int max = -1;
	for (int i = 0; i < answers.size(); i++)
	{
		if (student1[i % 5] == answers[i])
			cnt[0]++;
		if (student2[i % 8] == answers[i])
			cnt[1]++;
		if (student3[i % 10] == answers[i])
			cnt[2]++;
	}

	for (int i = 0; i < 3; i++)
	{
		if (max < cnt[i])
			max = cnt[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (max == cnt[i])
			answer.push_back(i + 1);
	}
	
	return answer;
}

int main() {
	solution({ 1,2,3,4,5 });
	return 0;
}