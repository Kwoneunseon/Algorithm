#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
public:
	int value;
	int index;
};

bool cmp(Node a, Node b) {
	if (a.value == b.value)
		return a.index < b.index;
	return a.value < b.value;
}

int solution(vector<int> cakes, int cnt, int M) {
	int v_size = cakes.size();
	vector<Node> v;

	Node temp;
	for (int i = 0; i < v_size; i++)
	{
		temp.value = cakes[i];
		temp.index = i;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	int i = 0;
	while (M != cnt) {
		int idx = v[i].index;
		if (idx == 0) {
			cakes[idx + 1] += cakes[idx];
		}
		else if (idx == cakes.size() - 1) {
			cakes[idx - 1] += cakes[idx];
		}
		else {
			if (cakes[idx - 1] > cakes[idx + 1])
				cakes[idx + 1] += cakes[idx];
			else
				cakes[idx - 1] += cakes[idx];
		}
		cakes.erase(cakes.begin() + idx);
		M--;
		i++;
	}
	int min = 4000001;
	for (int i = 0; i < cakes.size(); i++)
	{
		if (cakes[i] < min)
			min = cakes[i];

	}
	return min;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, cnt, cake_length;
	cin >> N >> M >> cake_length;
	vector<int> cakes;

	int front = 0, end;

	for (int i = 0; i < M; i++)
	{
		cin >> end;
		cakes.push_back(end - front);
		front = end;
	}
	cakes.push_back(cake_length - front);

	while (N--) {
		cin >> cnt;
		cout << solution(cakes, cnt, M);
	}
	return 0;
}