//복습 - 2021.02.27

#include <vector>
#include <cmath>

using namespace std;

vector<int>solution(int brown, int yellow) {
	vector<int> answer;

	for (int i = 1; i <= sqrt(yellow); i++)
	{
		int x, y;//x:가로 ,y:세로
		if (yellow%i == 0) {
			x = yellow / i;
			y = i;
			if (brown == ((x + 2)*(y + 2) - yellow)) {
				answer.push_back(x + 2);
				answer.push_back(y + 2);
				break;
			}
		}
	}

	return answer;
}

int main() {
	solution(24, 24);
	return 0;
}