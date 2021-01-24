#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//단순하게 생각해.
int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.rbegin(), people.rend());
	int first = 0 , second = people.size()-1;
	while (first <= second) {
		if (people[first] + people[second] <= limit) {
			first++;
			second--;
		}
		else {
			first++;
		}
		answer++;
	}


	return answer;
}

int main() {
	solution({ 70,80,50 }, 100);
	return 0;
}