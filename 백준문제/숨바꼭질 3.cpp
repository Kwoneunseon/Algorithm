#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int subin, sister, answer=987654321;
	//{현재 위치, 시간}
	cin >> subin >> sister;
	queue<pair<int, int>>q;
	q.push({ subin, 0 });
	int loc, time;
	while (!q.empty()) {
		loc = q.front().first;
		time = q.front().second;
		q.pop();
		int next_loc;
		//x-1로 움직이는 경우
		next_loc = loc - 1;
		if (next_loc > 0) {
			if (next_loc == sister) {
				time = time + 1;
				break;
			}
			q.push({ next_loc,time + 1 });
		}
		//x+1로 움직이는 경우
		next_loc = loc + 1;
		if (next_loc == sister) {
			time = time + 1;
			break;
		}
		q.push({ next_loc,time + 1 });
		//순간이동 2*x
		next_loc = 2 * loc;
		if (next_loc == sister)
			break;
		q.push({ next_loc, time });
	}

	cout << time;
	


	return 0;
}