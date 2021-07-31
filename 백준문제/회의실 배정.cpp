#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//원래 아이디어 : 시간의 차 순으로 오름차순 정렬
//정답 :  끝나는 시간을 기준으로 오름차순 정렬

bool compare( pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,first,last,answer= 1,max=-1;
	cin >> n;
	vector<pair<int, int> >schedule;

	for (int i = 0; i < n; i++)
	{
		cin >> first >> last;
		schedule.push_back({ first,last });
	}
	sort(schedule.begin(), schedule.end(),compare);
	//종료시간보다 나중에 있는 시작시간이 크거나 같다면 OK
	int now = schedule[0].second;
	for (int i = 1; i < n; i++)
	{
		if (now <= schedule[i].first) {
			answer++;
			now = schedule[i].second;
		}
	}
	

	cout << answer;
	return 0;
}