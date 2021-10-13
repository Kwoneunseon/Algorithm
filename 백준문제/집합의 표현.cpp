#include <iostream>
using namespace std;

int *parent;

//parent 노드 찾기
int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

//노드 a, b 합치기
void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
 }

//노드 a, b가 연결되어 있는지 확인하기
bool Find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return true;
	else
		return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> n >> m;
	parent = new int[n + 2];

	//parent배열 초기화
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	int cmd, a, b;
	while (m--) {
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			Union(a, b);
		}
		else if (cmd == 1) {
			if (Find(a, b))
				cout << "YES\n";
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}