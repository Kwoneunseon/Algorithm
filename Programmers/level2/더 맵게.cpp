#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cir(int first, int second, int&answer) {
	answer++;
	return first + 2 * second;
}

int solution(vector<int>scoville, int k) {
	int answer = 0;
	vector<int> temp;
	sort(scoville.begin(), scoville.end());
	for (int i = 0; i < scoville.size(); i++)
	{
		temp.push_back(scoville[i]);
		if (scoville[i] >= k) {
			break;
		}
	}


	int check;
	while(!temp.empty())
	{
		if (temp.size() == 1) {
			temp.erase(temp.begin(), temp.begin() + 1);
		}
		else {
			check = cir(temp[0], temp[1], answer);
			temp.erase(temp.begin(), temp.begin() + 2);
		}
		if (check < k) {
			temp.push_back(check);
			sort(temp.begin(), temp.end());
		}
	}



	return answer;
}

int main() {
	cout << solution({ 1,2,3,9,10,12 }, 7);

	return 0;
}