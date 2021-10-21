#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int train_size, M;
	cin >> train_size >> M;
	vector<vector<int> > train(train_size+1, vector<int>(21));
	vector<int>train_cal(train_size + 1);
	int command, i, x;//명령, i번쨰 기차, x 위치
	while (M--) {
		cin >> command >> i >> x;
		
		//사람이 태움
		if (command == 1) {
			if (train[i][x] != 1) {
				train_cal[i] += x;
				train[i][x] = 1;
			}

		}//사람을 하차시킴
		else if (command == 2) {
			if (train[i][x] == 1) {
				train_cal[i] -= x;
				train[i][x] = 0;
			}
		}//오른쪽으로 이동
		else if (command == 3) {
			int count = 0;
			for (int j = 20; j >=1; j--)
			{
				if (train[i][j] == 1) {
					count++;
					if (j == 20) {
						train[i][j] = 0;
						count -= 20;
					}
					train[i][j + 1] = train[i][j];
					train[i][j] = 0;
				}
			}
			train_cal[i] += count;
			
		}//왼쪽으로 이동
		else if (command == 4) {
			int count = 0;
			for (int j = 1; j <= 20; j++)
			{
				if (train[i][j] == 1) {
					count++;
					if (j == 1) {
						train[i][j] = 0;
					}
					train[i][j - 1] = train[i][j];
					train[i][j] = 0;
				}
			}
			train_cal[i] += count;
		}
	}
	int answer = 0;
	for (int k = 1; k <= train_size; k++)
	{
		vector<int> same;
		for (int j = k+1; j <= train_size; j++)
		{
			if (train_cal[k] == train_cal[j])
				same.push_back(j);
		}


	}


	return 0;
}