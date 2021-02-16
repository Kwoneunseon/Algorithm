//bfs사용
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int visit[51] = { 0, };
	bool flag = false;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target) {
			flag = true;
			break;
		}
	}
	if (!flag)
		return 0; // words에 target이 없는 경우
	words.push_back(begin);
	queue<pair<pair<string, int>,int* > >q;
	q.push(make_pair(make_pair(begin,words.size()-1),visit));// begin이므로
	while (!q.empty()) {
		string first_str = q.front().first.first;
		int str_idx = q.front().first.second;
		int check_idx = str_idx;
		int *check_visit = visit;
		if (str_idx == words.size() - 1) {
			check_idx = -1;
		}
		else {
			check_visit[str_idx] ++;
		}
		if (first_str == target) {
			answer = check_visit[str_idx];
			break;
		}
		q.pop();

		for (int i = check_idx+1; i < words.size()-1; i++)
		{
			int diff = 0;
			for (int j = 0; j < words[i].length()-1; j++)
			{
				if (first_str[j] != words[i][j])
					diff++;
			}
			if (diff == 1 && check_visit[i]==0) {
				check_visit[i]= check_visit[str_idx]+1;
				q.push(make_pair(make_pair(words[i], i), check_visit));
			}
		}
	}
	return answer;
}

int main() {

	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });

	return 0;
}