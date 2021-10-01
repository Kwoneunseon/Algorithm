#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



int roots[100001] = { 0, };
int sizes[100001];

void Union(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);
	if (n1 != n2) {
		if (n1 < n2) {
			roots[n2] = n1;
			sizes[n1] = sizes[n1] + sizes[n2];
		}
		else {
			roots[n1] = n2;
			sizes[n2] = sizes[n1] + sizes[n2];
		}
	}
}

int find(int n1) {
	if (n1 == roots[n1])
		return n1;
	else
		return roots[n1] = find(roots[n1]);
}

int getRoot(int n1) {
	if (roots[n1] == n1)
		return n1;
	return roots[n1] = getRoot(roots[n1]);
}

bool find(int n1, int n2) {
	n1 = getRoot(n1);
	n2 = getRoot(n2);
	if (n1 == n2) return true;
	else return false;
 }

vector < vector<int>>map;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;//¿Õ±¹ÀÇ ¼ö, µ¿¸Í°ü°è
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
	{
		roots[i] = i;
	}
	fill(sizes, sizes + N+1, 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		Union(a, b);
	}
	int CTP, H, H_root, K;
	cin >> CTP >> H >> K;
	
	

	return 0;
}