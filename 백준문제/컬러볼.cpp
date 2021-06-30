#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//���� �� ���� ���
// ������� �� �ִ� ���� �� = ���� �� - ���� ���� ���� ���� ũ���� ��(���ܽ������ �ϱ� ������)

class Ball {
public :
	int idx, color, size, sum;
};

bool compare(Ball a, Ball b) {
	if (a.size == b.size)
		return a.idx < b.idx;
	else
		return a.size < b.size;
}

int main() {
	int N,accum=0,c;
	cin >> N;
	vector<Ball> b(N);
	vector<int>answer(N),color_sum(N);
	for (int i = 0; i < N; i++)
	{
		b[i].idx = i;
		cin >> c>> b[i].size;
		b[i].color = c-1;
	}
	sort(b.begin(), b.end(), compare);
	for (int i = 0,j=0; i < N; i++)
	{
		for (; b[i].size > b[j].size; j++)
		{
			accum += b[j].size;
			color_sum[b[j].color] += b[j].size;
		}
		answer[b[i].idx] = accum - color_sum[b[i].color];
	}
	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}