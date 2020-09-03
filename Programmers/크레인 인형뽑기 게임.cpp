//2020.09.03
#include <iostream>
#include <vector>
using namespace std;

int answer = 0;


int solution(vector<vector<int> > board, vector<int> moves) {
	
	vector<int> ans;
	int move_size = moves.size() , board_size = board.size();
	for (int i = 0; i < move_size; i++)
	{
		int k = 0;
		while (k < board_size && board[k][moves[i]-1] == 0 )
			k++;
		if ( k >= board_size)
			continue;
		ans.push_back(board[k][moves[i] - 1]);
		board[k ][moves[i]-1] = 0;
		int ans_size = ans.size();
		if (ans_size >= 2 && ans[ans_size - 1] == ans[ans_size - 2]) {
			ans.erase(ans.begin() + ans_size - 1);
			ans.erase(ans.begin() + (ans_size - 2));
			answer += 2;
		}

	}

	cout << answer << endl;
	return answer;
}

int main() {
	vector< vector<int> >vec;
	// 확인 해보기 위해서
	vector<int>a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	vec.push_back(a);
	a.clear();
	a.push_back(0);
	a.push_back(0);
	a.push_back(1);
	a.push_back(0);
	a.push_back(3);
	vec.push_back(a);
	a.clear();
	a.push_back(0);
	a.push_back(2);
	a.push_back(5);
	a.push_back(0);
	a.push_back(1);
	vec.push_back(a);
	a.clear();
	a.push_back(4);
	a.push_back(2);
	a.push_back(4);
	a.push_back(4);
	a.push_back(2);
	vec.push_back(a);
	a.clear();
	a.push_back(3);
	a.push_back(5);
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	vec.push_back(a);
	a.clear();
	a.push_back(1);
	a.push_back(5);
	a.push_back(3);
	a.push_back(5);
	a.push_back(1);
	a.push_back(2);
	a.push_back(1);
	a.push_back(4);
	solution(vec, a);
	return 0;
}
