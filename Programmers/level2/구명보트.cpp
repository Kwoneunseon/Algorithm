#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//효율성 문제 2개 틀림..
int solution(vector<int> people, int limit) {
	int answer = people.size();
	sort(people.begin(), people.end());
	int cnt= 0;
	int idx = people.size();
	for (int i = 0; i < idx; i++)
	{
		for (int j = idx-1; j >i; j--)
		{
			if (people[i] + people[j] <= limit) {
				idx = j;
				cnt++;
				break;
			}
		}
	}
	answer = answer - cnt;
	return answer;
}

int main() {
	solution({ 70,80,50 }, 100);
	return 0;
}