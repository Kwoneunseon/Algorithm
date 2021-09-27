#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Card {
public:
	int front;
	int back;
	//check이 true면 앞, false면 뒤;
	bool check = true;
};

bool cmp(Card a, Card b) {
	if (a.check == b.check) {

		if (a.front == b.front)
			return a.back < b.back;
		else
			return a.front < b.front;
	}
	else if (a.check)
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m,a,b,command;
	cin >> n >> m;
	vector<Card> cards;

	//카드에 대한 정보를 입력 받는다.
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cards.push_back({ a,b,true });
	}
	
	while (m--) {
		sort(cards.begin(), cards.end(), cmp);
		cin >> command;
		for (int i = 0; i < n; i++)
		{
			//앞면일 경우
			if (cards[i].check && cards[i].front <= command) {
				cards[i].check = false;
			}
			//뒷면일 경우
			else if (!cards[i].check && cards[i].back <= command) {
				cards[i].check = true;
			}
			else
				break;
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (cards[i].check)
			answer += cards[i].front;
		else
			answer += cards[i].back;

	}

	cout << answer;
	return 0;
}