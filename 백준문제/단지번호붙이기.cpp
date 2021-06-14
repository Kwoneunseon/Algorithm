//2667
//bfsÀÌ¿ë
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> >map;
int visit[25][25];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N;


int solution(int a, int b) {
	int x, y, next_x, next_y;
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			next_x = x + dx[i];
			next_y = y + dy[i];
			if(next_x <N && next_x>=0&&next_y<N&& next_y>=0 &&!visit[next_x][next_y]){
				if (map[next_x][next_y] == 1) {
					q.push(make_pair(next_x, next_y));
				}
				visit[next_x][next_y] = true;;
			}
		}
	}
	return cnt;
}

int main(){
	string s_num;
	vector<int>answer;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s_num;
		vector<int> num;
		for (int j = 0; j < N; j++)
		{
			num.push_back(s_num[j] - '0');
		}
		map.push_back(num);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && map[i][j] == 1) {
				answer.push_back(solution(i, j));
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
	return 0;
}