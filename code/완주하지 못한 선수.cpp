#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string>completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	int i;

	for (i = 0; i < participant.size(); i++)
	{
		if (participant[i] != completion[i]) {
			return participant[i];
		}
	}
	return participant[i];
}