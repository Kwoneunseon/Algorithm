#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string>participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < participant.size()-1; i++)
	{
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
	}
	if(answer=="")
		answer = participant[participant.size() - 1];
	return answer;
}

int main() {
	solution({ "mis","stan","mis","ana"}, { "stan","mis","ana" });
		
}