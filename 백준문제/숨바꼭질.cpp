#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//중복되는 곳은 피해야한다.
bool visit[100001] = { false, };

bool valid(int n) {
	if (n < 0 || n>100000 || visit[n])
		return false;
	return true;
}

int main() {
	int answer = 0;
	int o_loc, y_loc;
	cin >> o_loc>>y_loc;
	queue<pair<int, int>>q;
	q.push(make_pair(o_loc, 0));
	visit[o_loc] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == y_loc) {
			answer = cnt;
			break;
		}
		if (valid(x + 1)) {
			visit[x + 1] = true;
			q.push({ x + 1,cnt + 1 });
		}
		if (valid(x - 1)) {
			visit[x - 1] = true;
			q.push({ x - 1,cnt + 1 });
		}
		if (valid(x * 2)) {
			visit[2 * x] = true;
			q.push({ x * 2,cnt + 1 });
		}		
	}
	cout << answer;

	return 0;
}