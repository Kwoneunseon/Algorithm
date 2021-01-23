#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(vector<string> a, vector<string>b){
	return a[1] > b[1];
}

int solution(vector<vector<string> > clothes) {
	int answer = 1;
	vector<string> clothes_name;
	int cnt[31];
	memset(cnt, 0, sizeof(cnt));
	sort(clothes.begin(), clothes.end(), cmp);
	for (int i = 0; i < clothes.size(); i++)
	{	
		if (clothes_name.empty()) {
			clothes_name.push_back(clothes[i][1]);
			cnt[0]++;
		}
		else if (clothes[i - 1][1] == clothes[i][1]) { //앞에 종류가 이미 있을 때
			for (int j = 0; j < clothes_name.size(); j++)
			{
				if (clothes_name[j] == clothes[i][1]) {
					cnt[j]++;
					break;
				}
			}
		}
		else {
			clothes_name.push_back(clothes[i][1]);
			cnt[clothes_name.size()-1]++;
		}
	}
	for (int i = 0; i < clothes_name.size(); i++)
	{
		answer *= (cnt[i]+1);
	}
	answer = answer - 1;
	return answer;
}

int main() {
	solution({ {"y","h"},{"b","e"},{"g","h"} });
	return 0;
}

//비슷한 풀이지만 간단한 코드
int solution_other(vector<vector<string> > clothes) {
	int answer = 0;
	unordered_map<string, int> clothes_cnt;
	for (int i = 0; i < clothes.size(); i++)
	{
		clothes_cnt[clothes[i][1]]++;
	}
	for (auto it = clothes_cnt.begin(); it != clothes_cnt.end(); it++) {
		answer *= (it->second + 1);
	}
	answer--;
	return answer;
}