#include <iostream>

using namespace std;
int map[21][21];
int dice[6];

int cmd_roll(int cmd) {
	int top = dice[0];
	switch (cmd)
	{	
	case 1: // µ¿
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[3];
		dice[3] = top;
		break;
	case 2: //¼­
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[5];
		dice[5] = top;
		break;
	case 3: //ºÏ
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[4];
		dice[4] = top;
		break;
	case 4://³²
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[2];
		dice[2] = top;
		break;
	default:
		break;
	}
}

void condition(int row,int col) {
	if (map[row][col] != 0) {
		dice[1] = map[row][col];
	}
	else
		map[row][col] = dice[1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, x, y, col, row,cmd;
	cin >> N >> M >> x >> y>>cmd;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}




	return 0;
}