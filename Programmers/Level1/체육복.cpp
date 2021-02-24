#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int *std = new int[n];
	memset(std, 0, sizeof(int)*n);
	for (int i = 0; i < reserve.size(); i++)
	{
		std[reserve[i]-1]++;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		std[lost[i]-1]--;
	}

	for (int i = 0; i < n; i++)
	{
		if (std[i] == -1) {
			if (i > 0 && std[i - 1] == 1) {
				std[i - 1] = 0;
				std[i]++; // 왼쪽에서 가져온다.
				continue;
			}
			else if (i < n - 1 && std[i + 1] == 1) {
				std[i + 1] = 0;
				std[i]++;//오른쪽에서 가져옴.
			}

		}
	}
	for (int i = 0; i < n; i++)
	{
		if (std[i] >=0)
			answer++;
	}


	return answer;
}

int main() {
	solution(5,{ 2,4 }, { 1,3,5 });
	return 0;
}