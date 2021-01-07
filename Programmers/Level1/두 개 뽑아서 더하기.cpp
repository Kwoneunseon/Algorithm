#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int>numbers) {
	vector<int>answer;
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i+1; j < numbers.size(); j++)
		{
			if (find(answer.begin(), answer.end(), numbers[i] + numbers[j]) == answer.end()) {
				answer.push_back(numbers[i] + numbers[j]);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	vector<int> ans;
	ans = find_solution({ 2,1,3,1,4 });
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}

vector<int> find_solution(vector<int>numbers) {
	vector<int> answer;
	set<int>st;
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j =i+1; j < numbers.size(); j++)
		{
			st.insert(numbers[i] + numbers[j]);
		}
	}
	answer.assign(st.begin(), st.end());

	return answer;
}
//set�� insert�ϸ� �ڵ� ���ĵȴ�.
//set�� ��� ���Ұ� �����ϴ�.