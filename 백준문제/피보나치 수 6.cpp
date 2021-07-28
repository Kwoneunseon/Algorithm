#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ll n;
	cin >> n;
	ll x1, x2, x3;
	x1 = 0;x2 = 1;
	for (ll i = 2; i <= n; i++)
	{
		x3 = (x1 +x2)%1000000007;
		x1 = x2 % 1000000007;
		x2 = x3 % 1000000007;
	}

	cout << x2;
	return 0;
}