#include <vector>
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
