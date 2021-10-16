//2021.02.27
//bfs»ç¿ë
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool dfs(string from, vector<vector<string>>tickets, vector<bool>&visit, vector<string>&answer, int cnt) {
	answer.push_back(from);
	if (cnt == tickets.size()) {
		return true;
	}
	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == from && visit[i] == false) {
			visit[i] = true;
			bool success = dfs(tickets[i][1], tickets, visit, answer, cnt + 1);
			if (success)
				return true;
			visit[i] = false;
		}
	}
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>>tickets) {
	vector<string> answer,temp;
	vector<bool>visited(tickets.size(), false);
	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, visited, answer, 0);
	return answer;
}

int main() {
	solution({ {"ICN","JFK"},{"HND","IAD"},{"JFK","HND"} });
	return 0;
}