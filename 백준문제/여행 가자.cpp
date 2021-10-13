#include <iostream>
using namespace std;

int *parent;

//parent노드 찾기
int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	//parent초기화
	parent = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j ++)
		{
			cin >> temp;
			//1이 나올떄만 i+1,j+1노드를 합친다.
			if (temp == 1) {
				Union(i + 1, j + 1);
			}
		}
	}
	int answer;
	bool flag = true;
	cin >> temp;
	answer = getParent(temp);
	for (int i = 1; i < m; i++)
	{
		cin >> temp;
		//각 노드의 parent가 기존 answer과 똑같지 않은 경우 break.
		if (answer != getParent(temp)) {
			flag = false;
			break;
		}

	}
	if (flag) {
		cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}