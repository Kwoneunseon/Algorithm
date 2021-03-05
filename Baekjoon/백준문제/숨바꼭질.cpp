#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	vector<int>answer;
	answer.push_back(100000);
	int o_loc, y_loc;
	cin >> o_loc>>y_loc;
	queue<pair<int, int>>q;
	q.push(make_pair(o_loc, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if ((y_loc == x - 1) || (y_loc == x + 1) || (y_loc == 2 * x)) {
			answer.push_back(cnt + 1);
			continue;
		}
		if(x-1<10000 && cnt < *min_element(answer.begin(),answer.end()))
			q.push(make_pair(x - 1,cnt+1));
		if (x +1 < 10000 && cnt < *min_element(answer.begin(), answer.end()))
			q.push(make_pair(x + 1,cnt+1));
		if (x *2 < 10000 && cnt < *min_element(answer.begin(), answer.end()))
			q.push(make_pair(2 * x,cnt+1));
	}
	cout << *min_element(answer.begin(),answer.end());

	return 0;
}