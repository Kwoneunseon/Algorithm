//https://gurumee92.tistory.com/164
//dp
//���� - 2021.02.27 (https://dvpzeekke.tistory.com/73)

#include <vector>
#include <string>
#include <algorithm>
#define MAX 9

int minDepth = MAX;

void dfs(int N, int number, int depth, int num) {
	if (depth >= MAX)
		return;
		

	if (num == number) {
		minDepth = min(depth, minDepth);
	}

	int operand = 0;
	for (int i = 0; i <= MAX ; i++)
	{
		operand = operand * 10 + N;

		dfs(N, number, depth + i, num + operand);
		dfs(N, number, depth + i, num- operand);
		if (num != 0) {
			dfs(N, number, depth + i, num*operand);
			dfs(N, number, depth + i, num/ operand);
		}
	}
}

int solution(int N, int number) {
	int answer = 0;
	dfs(N, number, 0, 0);
	answer = ((minDepth >= MAX) ? -1 : minDepth);

	return answer;
}