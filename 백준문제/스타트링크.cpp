#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mv[2];
bool visit[1000000] = { false, };
int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	mv[0] = u; mv[1] = -1 * d;
	queue<pair<int, int> > q;
	q.push({ s,0 });
	visit[s] = true;
	int loc, new_loc,cnt,flag=-1;
	while (!q.empty()) {
		loc = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (loc == g) {
			flag = 1;
			break;
		}
		for (int i = 0; i < 2; i++)
		{
			new_loc = loc + mv[i];
			if (new_loc >= 1 && new_loc <= f && !visit[new_loc]) {
				q.push({ new_loc,cnt + 1 });
				visit[new_loc] = true;
			}

		}
	}
	if (flag == 1) {
		cout << cnt;
	}
	else
		cout << "use the stairs";


	return 0;
}