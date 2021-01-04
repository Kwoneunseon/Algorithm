#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int>answer;
	int x, total;
	for (int i = 1; i <= sqrt(yellow); i++)
	{
		if (yellow % i == 0) {
			x = yellow / i;
			total = (x + 2)* (i + 2);
			if (brown == total - yellow) {
				answer.push_back(x + 2); 
				answer.push_back(i + 2);
				break;
			}
		}

	}

	return answer;
}
