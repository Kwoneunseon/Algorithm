//dfs»ç¿ë
#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer = 0;

void dfs(string begin, string target, vector<string>words,bool* visit, int cnt = 0) {

	for (int i = 0; i < words.size(); i++)
	{
		int diff = 0;
		for (int j = 0; j < words[i].size(); j++)
		{
			if (!visit[i] && begin[j] != words[i][j])diff++;
		}
		if (diff == 1) {
			if (words[i] == target) {
				answer = cnt + 1;
				break;
			}
			visit[i] = true;
			dfs(words[i], target, words, visit, cnt + 1);
			visit[i] = false;
		}
	}


}

int solution(string begin, string target, vector<string> words) {
	bool visit[51] = { false, };
	dfs(begin, target, words, visit);
	if (answer == 100) return 0;
	return answer;
}

int main() {

	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" ,"cog" });

	return 0;
}