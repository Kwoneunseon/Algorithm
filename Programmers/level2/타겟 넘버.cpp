//º¹½À - 2021.02.27

#include <vector>
#include <queue>

using namespace std;

bool visited[21] = { false, };

int solution(vector<int>numbers, int target) {
	int answer = 0;
	queue<pair<int, int> >q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int sum = q.front().first;
		int index = q.front().second;
		q.pop();
		if (sum == target && index == numbers.size())answer++;
		if (index < numbers.size() ) {
			q.push(make_pair(sum + numbers[index], index + 1));
			q.push(make_pair(sum - numbers[index], index + 1));
		}
	}
	   
	return answer;
}

int main() {
	solution({ 1,1,1,1 ,1}, 3);

	return 0;
}