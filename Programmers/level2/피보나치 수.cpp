#include <vector>

using namespace std;



int solution(int n) {
	int answer = 0;
	vector<int> fibonacci;
	fibonacci.push_back(0);
	fibonacci.push_back(1);
	while (fibonacci.size() <= n) {
		int idx = fibonacci.size() - 1;
		fibonacci.push_back(fibonacci[idx] + fibonacci[idx - 1]);
	}
	answer = fibonacci[n - 1];
	return answer;
}
int main() {
	solution(5);
	return 0;
}