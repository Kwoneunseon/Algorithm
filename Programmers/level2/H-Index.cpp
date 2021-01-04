#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations){
	int solution ;
	int temp = 0;
	bool flag = true;
	sort(citations.begin(), citations.end(),greater<int>());//Descending

	while (flag) {
		int big_cnt = 0, small_cnt = 0;
		for (int i = 0; i < citations.size(); i++)
		{
			if (citations[i] >= temp)big_cnt++;
			if (citations[i] < temp)small_cnt++;
		}
		if (big_cnt >= temp) {
			solution = temp;
			temp++;
		}
		else if(big_cnt < temp) flag = false;
	}


	return solution;
}


// clean code
int solution(vector<int>citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] >= (i + 1))
			answer++;
	}

	return answer;
}