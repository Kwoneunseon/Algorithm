#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, answer = 0;
	string s;
	cin >> N >> s;
	for (int i = 0; i < N; i++)
	{
		answer += (s[i] - '0');
	}
	cout << answer;
	return 0;
}