#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;
vector<int> a[MAX];
int d[MAX];
int c[MAX];
int n, m, k;

bool dfs(int x) {
	for (int i = 0;i < a[x].size();i++) {
		int t = a[x][i];
		if (c[t]) continue;
		c[t] = true;
		if(d[t] == 0 || dfs(t)){
			d[t] = x;
			return true;
		}
	 }
	return false;
}
int main(void) {
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) {
		int s;
		cin >> s;
		for (int j = 0;j < s;j++) {
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int count = 0, extra = 0;
	for (int i = 1;i <= n;i++) {
		fill(c, c + MAX, false);
		if (dfs(i))count++;
	}
	//2���۾��Ҽ� �ִ� ����� �߰������� ����մϴ�.
	for (int i = 1;i <= n && extra < k;i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) extra++;

	}
	cout << count + extra << "\n";
	return 0;
}