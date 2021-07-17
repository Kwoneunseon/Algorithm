#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int>q;
	int n,temp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (q.size()!=1) {
		cout << q.front()<<" ";
		q.pop();
		temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front(); // ¸¶Áö¸· ¿ø¼Ò »Ì¾ÆÁÜ.

	return 0;
}