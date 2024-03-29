#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix operator * (const matrix &a, const matrix &b) {
	ll size = a.size();
	matrix res(size, vector<ll>(size));

	for (ll i = 0; i < size; i++)
	{
		for (ll j = 0; j < size; j++)
		{
			for (ll k = 0; k < size; k++)
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000;
		}
	}
	return res;

}

matrix power(matrix a, ll n) {
	ll size = a.size();
	matrix res(size, vector<ll>(size));

	for (ll i = 0; i < size; i++)
	{
		res[i][i] = 1;
	}

	while (n > 0) {
		if (n % 2 == 1) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ll n, b;
	cin >> n >> b;
	matrix a(n, vector<ll>(n));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	a= power(a, b);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cout << a[i][j]<<" ";
		}
		cout << "\n";
	}
	


	return 0;
}