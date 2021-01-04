#include <vector>
#include <algorithm>
#include <iostream>
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

int main() {
	cout << solution({3, 0, 6, 1, 5} )<< endl;
	return 0;
}