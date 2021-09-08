#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//N이 백만이 들어올 것을 감안해서
bool nums[1004000] = { true, };

void erathos() {
	nums[1] = false;
	for (int i = 2; i <=1004000 ; i++)
	{
		if (nums[i] == false)
			continue;
		for (int j = i+i; j <= 1004000; j+=i)
		{
			nums[j] = false;
		}
	}
}

bool check_palin(int n) {
	string str = to_string(n);
	for ( int i = 0; i <str.size()/2; i++)
	{
		if (str[i] != str[str.size() - i - 1])
			return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(nums, true, sizeof(nums));

	int n;
	string s;
	cin >> n;
	erathos();
	for (int i = n; ; i++)
	{
		if (nums[i] && check_palin(i)){
			cout << i;
			break;
		}
	}


	return 0;
}