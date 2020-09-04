//2020.09.05 - 첫번째시도
//4개의 test케이스 실패
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>prior, int location){
	int answer = 1;
	int min_idx = prior.size(),min = 10;
	for (int i = 0; i < prior.size(); i++)
	{
		//큰애들은 먼저 실행되니까 먼저 카운트해준다.
		if (prior[location] < prior[i]) {
			if (min >= prior[i]) {
				min_idx = i;
				min = prior[i];
			}

			answer++;
		}
	}
	int i = min_idx;
	while (i != location) {
		if (i == prior.size()) {
			i = 0;
			if (i == location) {
				return answer;
			}
		}
		if (prior[location] == prior[i])
			answer++;
		i++;
	}

	return answer;
}

int main() {
	int prior[] = {1,1,9,1,1,1};
	vector<int> vec;
	for (int i = 0; i < 6; i++)
	{
		vec.push_back(prior[i]);
	}
	int temp = solution(vec, 0);
	cout << temp;

	return 0;
}