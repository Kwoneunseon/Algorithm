#include <iostream>
#include <string>
using namespace std;
//R_cntArr : R내의 각 문자 개수
//Win_cntArr :윈도우 내의 각 문자 개수
int minSub(string s, string r) {
	int WIn_cntArr[53] = { 0, }, R_cntArr[53] = { 0, };
	int start = 0, end = 0, window_lenth = 0, count = 0;
	int s_len = s.length(), r_len = r.length();
	int min = s_len + 1;
	for (int i = 0; i < r_len; i++)
	{
		if ('A' <= r[i]&& r[i] <= 'Z') //대소문자 구분안한다고 가정
			R_cntArr[r[i] - 'A']++;
		else if ('a' <= r[i] && r[i] <= 'z')
			R_cntArr[r[i] - 'a'+26]++;
	}
	//cnt_arr생성
	while (end <= s_len) {
		if ('a' <= s[end]&& s[end] <= 'z')
			WIn_cntArr[s[end] - 'a'+26] = WIn_cntArr[s[end]-'a' + 26] + 1;
		else if ('A' <= s[end] && s[end] <= 'Z') {
			WIn_cntArr[s[end] - 'A'] = WIn_cntArr[s[end] - 'A'] + 1;
		}
		if ('a' <= s[end] && s[end] <= 'z') {
			if (R_cntArr[s[end] - 'a' + 26] >= WIn_cntArr[s[end] - 'a' + 26]) {
				count = count + 1;
			}
		}
		else if ('A' <= s[end] && s[end] <= 'Z') {
			if (R_cntArr[s[end]-'A'] >= WIn_cntArr[s[end]-'A']) {
				count = count + 1;
			}
		}

		while (count == r_len) {
			window_lenth = end - start + 1;
			if (window_lenth < min) {
				min = window_lenth;
			}
			if ('A' <= s[start] && s[start] <= 'Z') {
				if (R_cntArr[s[start]-'A'] >= WIn_cntArr[s[start]-'A'] ) {
					count = count - 1;
				}
			}
			else if ('a' <= s[start] && s[start] <= 'z') {
				if (R_cntArr[s[start] - 'a' + 26] >= WIn_cntArr[s[start]-'a' + 26]) {
					count = count - 1;
				}
			}
			if ('A' <= s[start] && s[start] <= 'Z') {
				WIn_cntArr[s[start]-'A'] = WIn_cntArr[s[start]-'A']-1;
			}
			else if ('a' <= s[start] && s[start] <= 'z') {
				WIn_cntArr[s[start]-'a' + 26] = WIn_cntArr[s[start]-'a' + 26]-1;
			}
			start = start + 1;
		}
		end = end + 1;
	}
	if (min > s_len) {
		return 0;
	}
	return min;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s, r;
		cin >> s >> r;
		cout << minSub(s, r)<<"\n";
	}
	return 0;
}