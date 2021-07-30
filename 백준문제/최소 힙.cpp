#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N,temp;
	cin >> N;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == 0) {
			if (pq.empty())
				cout << 0<<"\n";
			else {
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}


	return 0;
}