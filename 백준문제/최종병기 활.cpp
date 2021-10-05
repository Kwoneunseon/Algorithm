#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int>length;
	
	int first, last,start;
	cin >> first;
	start = first;
	for (int i = 0; i < M; i++)
	{
		cin >> last;
		length.push_back(last - first);
		first = last;
		if (i == M - 1) {
			length.push_back(N - last + start);
		}
	}


	return 0;
}