#include <iostream>
#include <string>
#define MAX 1e5

using namespace std;

bool not_prime_check[100002];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//에라토스테네스의 체-> 소수 체크하기
	not_prime_check[1] = true;
	for (int i = 2; i <= MAX; i++)
	{
		if (not_prime_check[i])
			continue;
		for (int j = 2; i*j <= MAX; j++)
		{
			not_prime_check[i*j] = true;
		}
	}
	string s_number;
	while (true) {
		cin >> s_number;
		if (s_number == "0")
			break;
		for (int i = MAX; i >=2; i--)
		{
			//소수 중에 s_number에 들어 있으면 그 수가 가장 큰 소수 부분 문자열이다.
			if (!not_prime_check[i]) {
				string s_temp = to_string(i);
				if (s_number.find(s_temp) != string::npos) {
					cout << s_temp << "\n";
					break;
				}
			}
		}


	}


	return 0;
}