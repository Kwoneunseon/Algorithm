#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;

class info {
public:
	int x, y;
	info() {
		x = 101, y = 101;
	}
	info(int a, int b) {
		this->x = a;
		this->y = b;
	}
	bool operator < (info &a) {
		return this->x < a.x;
	}
};
bool compare(int a, int b) {
	return a > b;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;//n: 축의 크기, m:카드의 개수
		char alpha;
		int x, y;
		cin >> n >> m;
		int **arr = new int*[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
			memset(arr[i], -1, sizeof(int)*n);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> alpha;
			cin >> x >> y;
			arr[x][y] = alpha - 'A';
		}
		for (int k = 0; k < 26; k++)//알파벳은 26개이므로
		{
			vector<info>check;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == k) {
						info temp(i, j);
						check.push_back(temp);
					}
				}
			}
			sort(check.begin(), check.end());
			int size = check.size(), len, min = n * n * 2 + 1;
			info min_info;
			int **min_check = new int*[size];
			for (int j = 0; j < size; j++)
			{
				min_check[j] = new int[size];
				memset(min_check[j], 0, sizeof(int)*size);
			}
			bool *next = new bool[size];
			for (int i = 0; i < size; i++)
			{
				next[i] = true;
			}
			if (size >= 2) { //아예 들어있지 않는 경우는 제외한다.
				for (int i = 0; i < size-1; i++)
				{
					for (int j = i+1; j < size; j++)
					{
						len =(int) pow(check[i].x - check[j].x, 2) + pow(check[i].y - check[j].y, 2);
						min_check[i][j] = len;

						if (len <= min && len != 0) {
							if (len == min && check[min_info.y].y + check[min_info.x].y > check[j].y + check[i].y) {
								min = len;
								min_info = info(i, j);
							}
							else if (len == min && check[min_info.y].y + check[min_info.x].y == check[j].y + check[i].y) {
								if (check[min_info.y].x + check[min_info.x].x > check[j].x + check[i].x) {
									min = len;
									min_info = info(i, j);
								}
								else
									continue;
							}
							else if (len < min) {
								min = len;
								min_info = info(i, j); //다른의미이기는 하지만 여기선 어차피 두개 의 수를 저장한다는 의미에서 쓰임.
							}
						}
					}
				}
				cout << (char)(k + 'A') << " ";
				if (check[min_info.x].y > check[min_info.y].y) {
					int temp = min_info.x;
					min_info.x = min_info.y;
					min_info.y = temp;
				}
				else if(check[min_info.x].y == check[min_info.y].y&& check[min_info.x].x > check[min_info.y].x) {
					int temp = min_info.x;
					min_info.x = min_info.y;
					min_info.y = temp;
				}
				cout <<check[min_info.x].x << " " << check[min_info.x].y << " " << check[min_info.y].x << " " << check[min_info.y].y << "\n";
				next[min_info.x] = false, next[min_info.y] = false;
				int size_temp = size-2;
				while (size_temp != 0) {
					min = n * n * 2 + 1;
					for (int i = 0; i < size - 1; i++)
					{
						for (int j = i + 1;j < size; j++)
						{
							if (next[i] == true && next[j] == true && min_check[i][j] <= min) {
								if (min_check[i][j] == min && check[min_info.y].y + check[min_info.x].y > check[j].y + check[i].y) {
									min = min_check[i][j];
									int temp_x = i, temp_y = j;
									if (check[i].y > check[j].y) {
										temp_x = j, temp_y = i;
									}
									else if (check[i].y == check[j].y && check[i].x > check[j].x) {
										temp_x = j, temp_y = i;
									}
									min_info = info(temp_x, temp_y);
								}
								else if (min_check[i][j] == min && check[min_info.y].y + check[min_info.x].y == check[j].y + check[i].y) {
									if (check[min_info.y].x + check[min_info.x].x > check[j].x + check[i].x) {
										min = min_check[i][j];
										int temp_x = i, temp_y = j;
										if (check[i].y > check[j].y) {
											temp_x = j, temp_y = i;
										}
										else if (check[i].y == check[j].y && check[i].x > check[j].x) {
											temp_x = j, temp_y = i;
										}
										min_info = info(temp_x, temp_y);
									}
									else
										continue;
								}
								else if(min_check[i][j] < min){
									min = min_check[i][j];
									int temp_x = i, temp_y = j;
									if (check[i].y > check[j].y) {
										temp_x = j, temp_y = i;
									}
									else if (check[i].y == check[j].y && check[i].x > check[j].x) {
										temp_x = j, temp_y = i;
									}
									min_info = info(temp_x, temp_y);
								}
							}
						}
					}
					size_temp = size_temp - 2;
					cout << (char)(k + 'A')<<" ";
					cout << check[min_info.x].x <<" "<< check[min_info.x].y << " " << check[min_info.y].x << " " << check[min_info.y].y << "\n";
					next[min_info.x] = false, next[min_info.y] = false;

				}
			}
		}//알파벳 하나당 출력하기

	}

	return 0;
}