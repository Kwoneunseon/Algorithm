#include <vector>	
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue< pair <int, int> > prior;
	for (int i = 0; i < priorities.size(); i++)
	{
		if (i == location) {
			prior.push(make_pair(priorities[i], 1));
			continue;
		}
		prior.push(make_pair(priorities[i], 0));
	}
	sort(priorities.rbegin(), priorities.rend()); 
	int i = 0, time = 0,temp1, temp2;
	while (true) {
		if (priorities[i] == prior.front().first) {
			answer++;
			i++;
			if (prior.front().second == 1) {
				break;
			}
			prior.pop();

		}
		else {
			temp1 = prior.front().first;
			temp2 = prior.front().second;
			prior.pop();
			prior.push(make_pair(temp1,temp2));
		}
	}
	return answer;

}


//다른 사람 클린 코드
int solution1(vector<int> priorities, int location) {
	int answer = 0;
	vector<int> sorted;
	queue<int>prior;
	//queue에 인덱스를 표시하기 위한 value를 집어넣는다.
	for (int i = 0; i <priorities.size(); i++)
	{
		prior.push(i);
	}
	int idx;
	while (!prior.empty()) {
		idx = prior.front();
		prior.pop();	
		if (priorities[idx] == *max_element(priorities.begin(), priorities.end())) {
			priorities[idx] = 0;
			sorted.push_back(idx);
		}
		else {
			prior.push(idx);
		}
	}

	//인덱스를 저장하고 그걸 이용함.
	for (int i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] == location){
			answer = i + 1;
			break;
		}
	}

	return answer;
}