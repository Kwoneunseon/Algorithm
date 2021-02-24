#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int>moves) {
	int answer = 0;
	stack<int> s[31];
	for (int i = 4; i >= 0 ; i--)
	{
		for (int j = 1; j <= board.size(); j++)
		{
			if (board[i][j-1] != 0)
				s[j].push(board[i][j-1]);
		}
	}
	stack<int> check;

	for (int i = 0; i < moves.size(); i++) {

		if (s[moves[i]].empty())
			continue;

		int temp = s[moves[i]].top();
		s[moves[i]].pop();
		if (check.size() != 0 && check.top() == temp) {
			answer++;
			check.pop();
		}
		else {
			check.push(temp);
		}
	}

	answer = answer * 2;
	return answer;
}

int main() {
	solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1},{4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} }, { 1,5,3,5,1,2,1,4 });
	return 0;
}
