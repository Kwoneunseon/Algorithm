//dfs사용
//복습 - 2021.02.27

#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string c_begin, c_target;
vector<string>c_words;
vector<int>v;
int answer = 0;

void dfs(string begin, string target,vector<string>words, bool visited[], int count = 0) {
	for (int i = 0; i < words.size(); i++)
	{
		int diff = 0;
		for (int j = 0; j < words[i].length(); j++)
		{
			if (!visited[i] && begin[j] != words[i][j])diff++;
		}
		if (diff == 1) {
			if (words[i] == target) {
				answer = count +1;
				break;
			}
			visited[i] = true;
			dfs(words[i], target, words, visited, count + 1);
			visited[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string>words) {
	bool visited[51] = { false, };
	dfs(begin, target, words, visited);
	if (answer == 100)
		return 0;
	return answer;
}

int main() {

	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" ,"cog" });

	return 0;
}