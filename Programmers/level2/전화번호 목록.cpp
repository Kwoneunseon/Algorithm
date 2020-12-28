#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (string s1 : phone_book)
	{
		for (string s2 : phone_book) {
			if (s1 == s2) {
				continue;
			}
			if (s1.length() > s2.length()) {
				if (s2 == s1.substr(0, s2.size())) {
					return false;
				}
			}
		}
	}

	return answer;
}
