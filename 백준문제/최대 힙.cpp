#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> pq;

	int N , cmd;
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
		else {
			pq.push(cmd);
		}
	}

	return 0;
}