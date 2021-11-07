#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Node {
public:
	int index;
	int dist;
};
int Max = -1,farNode;
vector<Node> v[101];
bool visit_edge[101] = { false, };

void dfs(int index, int sum_dist) {
	if (visit_edge[index])
		return;
	if (Max < sum_dist) {
		Max = sum_dist;
		farNode = index;
	}
	for (int i = 0; i < v[index].size(); i++)
	{
		dfs(v[index][i].index, sum_dist+ v[index][i].dist);
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,first,second,dist;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		cin >> first >> second >> dist;
		v[first].push_back({ second,dist });
		v[second].push_back({ first,dist });
	}

	dfs(1, 0);
	Max = -1;
	memset(visit_edge, false, sizeof(visit_edge));
	dfs(farNode, 0);
	cout << Max;
	return 0;
}