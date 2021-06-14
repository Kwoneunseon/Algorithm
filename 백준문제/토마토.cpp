#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int row, col, tomato = 0, day = -1, tcnt = 0;
vector<vector<int> >box;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool check_tomato[1000][1000] = { false, };
vector<pair<int, int> > start;

void bfs() {
	queue<queue<pair<int, int> > > q;
	queue<pair<int, int> > ele;
	
	int x, y;
	for (int i = 0; i < start.size(); i++)
	{
		x = start[i].first;
		y = start[i].second;
		ele.push(start[i]);
		check_tomato[x][y] = true;
	}
	q.push(ele);
	while (!q.empty()) {
		queue<pair<int, int> > new_ele;
		day++;
		ele = q.front();
		q.pop();
		while (!ele.empty()) {
			x = ele.front().first;
			y = ele.front().second;
			ele.pop();
			check_tomato[x][y] = true;
			for (int i = 0; i < 4; i++)
			{
				int nextX = x + dx[i];
				int nextY = y + dy[i];
				if (nextX < row&&nextX >= 0 && nextY < col&&nextY >= 0 && check_tomato[nextX][nextY] == false) {
					if (box[nextX][nextY] == 0) {
						box[nextX][nextY] = 1;
						tcnt++;
						new_ele.push(make_pair(nextX, nextY));
					}
				}
			}
		}
		if (!new_ele.empty()) {
			q.push(new_ele);
		}
	}
}

int main() {
	cin >> col >> row;
	int temp;
	for (int i = 0; i < row; i++)
	{
		vector<int>v;
		for (int j = 0; j < col; j++)
		{
			cin >> temp;
			if (temp != 0) {
				if (temp == 1) {
					start.push_back(make_pair(i, j));
				}
				tomato++;
			}
			v.push_back(temp);
		}
		box.push_back(v);
	}
	tomato = row * col - tomato;

	bfs();
	if (tcnt != tomato)
		day = -1;
	cout << day;

	return 0;
}