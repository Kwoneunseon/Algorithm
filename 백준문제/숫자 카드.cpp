//10815
//ÀÌºÐÅ½»ö
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long >cards;

int bicheck(int start, int end,long long target) {
	if (start > end)return 0;
	int mid = (start + end) / 2;
	if (cards[mid] == target) return 1;
	else if (cards[mid] > target)
		return bicheck(start, mid - 1, target);
	else
		return bicheck(mid + 1, end, target);
}

int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	long long temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		cards.push_back(temp);
	}
	cin >> M;
	sort(cards.begin(), cards.end());
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		cout << bicheck(0, N - 1, temp)<<" ";
	}

	return 0;
}