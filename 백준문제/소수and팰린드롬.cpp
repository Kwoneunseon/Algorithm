#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool nums[1000001] = { true, };

void erathos() {
	for (int i = 2; i <=1000000 ; i++)
	{
		if (nums[i] == false)
			continue;
		for (int j = i+i; j <= 1000000; j+=i)
		{
			nums[j] = false;
		}
	}
}

bool check_palin(int n) {
	string str = to_string(n);
	for ( int i = 0; i <str.length()/2; i++)
	{
		if (str[i] != str[str.size() - i - 1])
			return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	string s;
	cin >> n;
	for (int i = n; ; i++)
	{
		if (nums[i] && check_palin(i)){
			cout << i;
			break;
		}
	}


	return 0;
}