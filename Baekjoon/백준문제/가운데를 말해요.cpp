//1655
//우선순위 큐를 사용
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt,num;
	cin >> cnt;
	priority_queue<int, vector<int>, greater<int> >max;
	priority_queue<int, vector<int>, less<int> > min;
	for (int i = 0; i < cnt; i++)
	{
		cin >> num;
		if (min.size() == 0) {
			min.push(num);
		}
		else {
			if (min.size() > max.size()) {
				max.push(num);
			}
			else {
				min.push(num);
			}
			if (min.top() > max.top()) {
				int mintop = min.top();
				int maxtop = max.top();
				max.pop();
				min.pop();
				max.push(mintop);
				min.push(maxtop);
			}
		}
		cout << min.top() << "\n";
	}


	return 0;
}