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
