//2021.02.27
//bfs사용
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

vector<string>solution(vector<vector<string>>tickets) {
	vector<string>answer;
	vector<string>airport;
	vector<vector<int>>tickets_int(10000);
	int start_idx;
	for (int i = 0; i < tickets.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			bool flag = true;
			for (int k = 0; k < airport.size(); k++)
			{
				if (tickets[i][j] == airport[k])
					flag = false;
			}
			if (flag) {
				airport.push_back(tickets[i][j]);
			}
		}
	} // 어떤 공항이 있는지 확인한다.
	sort(airport.begin(), airport.end(),less<string>());
	for (int i = 0; i < airport.size(); i++)
	{
		if (airport[i] == "ICN")
			start_idx = i;
	}

	vector<vector<string>> check(10000);
	for (int i = 0; i < tickets.size(); i++)
	{
		int x, y;
		for (int j = 0; j < airport.size(); j++)
		{
			if (airport[j] == tickets[i][0]) {
				x = j;
				break;
			}
		}
		for (int j = 0; j < airport.size(); j++)
		{
			if (airport[j] == tickets[i][1]) {
				y = j;
				break;
			}
		}
		tickets_int[x].push_back(y);
	} //숫자로 바꿔준다.	
	for (int i = 0; i < tickets_int.size(); i++)
	{
		if(!tickets_int[i].empty())
			sort(tickets_int[i].begin(), tickets_int[i].end());
	}
	int cur = start_idx;
	answer.push_back(airport[cur]);
	while (!tickets_int[cur].empty()) {
		int next = tickets_int[cur][0];
		tickets_int[cur].erase(tickets_int[cur].begin(), tickets_int[cur].begin() + 1);
		answer.push_back(airport[next]);
		cur = next;
	}




	return answer;
}

int main() {
	solution({ {"ICN","JFK"},{"HND","IAD"},{"JFK","HND"} });
	return 0;
}