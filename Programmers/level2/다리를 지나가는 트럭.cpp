#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> bridge;
	int  sum = 0, i = 0;
	while (true) {
		if (answer >= bridge_length) {
			if (bridge.front()==-1) { //������ Ʈ���� ���������� ǥ��
				break;
			}
			sum -= bridge.front();
			bridge.pop();
		}
		//��� Ʈ���� ���� ���.
		if (i < truck_weights.size() && sum + truck_weights[i] <= weight) {
			bridge.push(truck_weights[i]);
			sum += truck_weights[i];
			i++;
			if (i == truck_weights.size()) {
				bridge.push(-1);
			}
			answer++;
		}
		else {
			bridge.push(0);
			answer++;
		}
	}
	return answer;
}
