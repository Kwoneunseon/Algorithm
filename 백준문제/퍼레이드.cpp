#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

class Node {
public:
	int next;
	int connect_index;
};

vector<Node>v[3001];
bool visit_edge[3001] = { false, };
bool visit_node[3001] = { false, };

void dfs(int start) {
	Node new_x;
	for (int i = 0; i < v[start].size(); i++)
	{
		new_x = v[start][i];
		if (!visit_edge[new_x.connect_index]) {
			visit_edge[new_x.connect_index] = true;
			visit_node[new_x.next] = true;
			dfs(new_x.next);
			break;
		}

	}
}

bool check_visit(int v, int e) {
	bool flag = true;
	for (int i = 1; i <= v; i++)
	{
		if (visit_node[i] == false) {
			flag = false;
			break;
		}
	}
	for (int i = 0; i < e; i++)
	{
		if (!visit_edge[i]) {
			flag = false;
			break;
		}
	}
	return flag;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E,start,end;
	bool flag=true;
	cin >> V >> E;
	for (int i= 0; i <E; i++)
	{
		cin >> start >> end;
		v[start].push_back({ end,i });
		v[end].push_back({ start,i });
	}
	for (int i = 1; i <= V; i++)
	{
		//모든 노드에서 시작해서 다 확인하기 위해서
		memset(visit_edge, false, E + 1);
		memset(visit_node, false, V + 2);
		dfs(i);
		if (check_visit(V, E)) {
			cout << "YES";
			flag = false;
			break;			
		}
	}
	if (flag)
		cout << "NO";



	return 0;
}