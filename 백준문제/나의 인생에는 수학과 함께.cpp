#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char map[6][6] = { 0, };
bool visit[6][6] = { false, };

int dx[] = { 1,0 };
int dy[] = { 0,1};


int N;

class Node {
public:
	int x;
	int y;
	bool number;
	char op;
	int sum = 0;
};

vector<int> bfs(int start_x, int start_y) {
	int x, y, new_x, new_y, sum =0,cal_sum;
	queue<Node> q;
	vector<int>answer;
	char op='+';
	q.push({ start_x,start_y,true,op,(map[start_x][start_y]-'0') });
	while (!q.empty()) {
		Node first = q.front();
		q.pop();
		x = first.x;
		y = first.y;
		if(x==3&& y==4){
		
		}
			
		bool number = first.number;
 		sum = first.sum;
		op = first.op;

		if (x == N - 1 && y == N - 1)
			answer.push_back(sum);

		for (int i = 0; i < 2; i++)
		{
			new_x = x + dx[i];
			new_y = y + dy[i];

			if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < N && !visit[new_x][new_y]) {
				if (!number) {
					if (map[new_x][new_y] >= '0' && map[new_x][new_y] <= '5') {
						if (op == '+')
							cal_sum = sum +(map[new_x][new_y]-'0');
						else if (op == '-')
							cal_sum =sum - (map[new_x][new_y]-'0');
						else if (op == '*')
							cal_sum  = sum * (map[new_x][new_y]-'0');

						//visit[new_x][new_y] = true;
						q.push({ new_x,new_y,true,op, cal_sum});
					}
				}
				else {
					if (map[new_x][new_y] == '+' || map[new_x][new_y] == '-' || map[new_x][new_y] == '*') {
						op = map[new_x][new_y];
						q.push({ new_x,new_y,false,op,sum});
					}

				}
			}


		}
	}
	return answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> map[row][col];
		}
	}
	vector<int>answer = bfs(0, 0);
	sort(answer.begin(), answer.end());

	cout << answer[answer.size() - 1] << " " << answer[0];


	return 0;
}