#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

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

//Hash를 이용해서 풀 경우
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> h;
	for (auto elem : completion) {
		if (h.end() == h.find(elem)) {
			h.insert(make_pair(elem, 1));
		}
		else {
			h[elem]++;
		}
	}

	for (auto elem : participant) {
		if (h.end() == h.find(elem)) {
			answer = elem;
			break;
		}
		else {
			h[elem]--;
			if (h[elem] < 0) {
				answer = elem;
				break;
			}
		}
	}
	return answer;
}