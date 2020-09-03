//2020.09.03
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;	
	int i = 0;
	sort(d.begin(), d.end());
	while (budget > 0 && i < d.size()) {
		if (budget >= d[i]) {
			answer++;
			budget = budget - d[i];
		}
		else if (budget < d[i]) {
			budget = budget - d[i];
		}
		i++;

	}

	return answer;
}
