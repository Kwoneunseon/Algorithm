//복습 - 2021.02.25
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	for (int i = 0; i < progresses.size(); i++)
	{
		if ((100 - progresses[i]) % speeds[i] == 0)
			progresses[i] = (100 - progresses[i]) / speeds[i];
		else
			progresses[i] = (100 - progresses[i]) / speeds[i] + 1;
	}
	int *check = new int[progresses.size()];
	memset(check, 0, sizeof(int)*progresses.size());
	int i = 0,cnt=0;
	while(i!=progresses.size()){
		if (check[i] != 0) {
			i++;
			continue;
		}
		int max_day = progresses[i];
		for (int j = i; j < progresses.size(); j++)
		{
			if (check[j]==0&&max_day >= progresses[j]) {
				check[j] = 1;
				cnt++;
			}
			else {
				break;
			}
		}
		answer.push_back(cnt);
		cnt = 0;
		i++;


	}

	return answer;
}
int main() {
	solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1 });
	return 0;
}