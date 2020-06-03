#include <iostream>
#include <queue>
using namespace std;
int dx[8] = { -1,-2,-2,-1,1,2,1,2 };
int dy[8] = { -2,-1,1,2,-2,-1,2,1 };
class pro {
public:
	int d, x, y;
	pro(int a, int b, int c) {
		this->d = a;
		this->x = b;
		this->y = c;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int L, start_x, start_y, finish_x, finish_y;
		int dist[500][500] = { 0, };
		fill(&dist[0][0], &dist[499][500], -1);
		cin >> L >> start_x >> start_y >> finish_x >> finish_y;
		queue<pro> q;
		pro k(0, start_x, start_y);
		q.push(k);
		int next_x, next_y;
		dist[start_x][start_y] = 0;
		while (!q.empty()) {
			pro temp = q.front();
			q.pop();
			if (temp.y == finish_y && temp.x == finish_x) {
				cout << temp.d<<"\n";
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				next_x = temp.x + dx[i];
				next_y = temp.y + dy[i];
				if (next_y >= 0 && next_x >= 0 && next_x < L && next_y < L&&dist[next_x][next_y] == -1) {
					dist[next_x][next_y] = dist[temp.x][temp.y] + 1;
					pro t1(dist[next_x][next_y], next_x, next_y);
					q.push(t1);
				}
			}

		}
	}

	return 0;
}