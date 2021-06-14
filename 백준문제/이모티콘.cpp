//14226
//bfs»ç¿ë
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visit[1001] = { false ,};

int main() {
	int emo, next_emo ,answer,cnt = 0;
	cin >> answer;
	queue<pair<int,int> >q;
	q.push(make_pair(1,0));
	visit[1] = true;
	while (!q.empty()) {
		emo = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (emo == answer) {
			cout << cnt;
			return 0;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == 0){
				next_emo = emo * 2;
				cnt += 2;
			}
			else if (i == 2) {
				next_emo = emo - 1;
				cnt += 1;
			}

			if (!visit[next_emo]) {
				q.push(make_pair(next_emo,cnt));
				visit[next_emo] = true;
			}
		}
	}


	return 0;
}