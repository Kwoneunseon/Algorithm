//1715번
//그리디 알고리즘 -> priority queue사용
#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, card,sum =0;
	priority_queue<int,vector<int>,greater<int>>q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> card;
		q.push(card);

	}
	int first, second;
	while (q.size() != 1) {
		first = q.top();
		q.pop();
		second = q.top();
		q.pop();
		q.push(first + second);
		sum += first + second;
	}
	cout << sum;

	return 0;
}