#include <iostream>

using namespace std;

int tree[500001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int node, rain,child_count= 0;
	cin >> node >> rain;
	
	int a, b;
	for (int i = 0; i < node-1; i++)
	{
		cin >> a >> b;
		if (tree[a] < 2)
			tree[a]++;
		if (tree[b] < 2)
			tree[b]++;
	}

	for (int i = 2; i <= 500000; i++)
	{	
		if(tree[i]==1) child_count++;
	}

	cout << fixed;
	cout.precision(6);
	//float(4byte)과 double(8byte)의 차이 알아둬
	cout << (double)rain/child_count;

	return 0;
}