//2021.02.04 - º¹½À

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers){
	vector<int> answer;
	int check[201] = { 0, };

	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i+1; j < numbers.size(); j++)
		{
			if (check[numbers[i] + numbers[j]] == 0) {
				check[numbers[i] + numbers[j]] = 1;
				answer.push_back(numbers[i] + numbers[j]);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	solution({ 5,0,2,7 });
	return 0;
}