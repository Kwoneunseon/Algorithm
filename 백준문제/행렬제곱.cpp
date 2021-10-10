#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector < vector<ll> > Matrix;

Matrix operator  * (const Matrix &a, const Matrix &b) {
	ll n = a.size();
	Matrix re_mat(n,vector<ll>(n));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			for (ll k = 0; k< n; k++)
			{		
				re_mat[i][j] += a[i][k] * b[k][j];
			}
			re_mat[i][j] %= 1000;
		}
	}
	return re_mat;
}

Matrix power(Matrix a, ll n) {
	ll size = a.size();
	Matrix re_mat(size, vector<ll>(size));
	for (ll i = 0; i < size; i++)
	{
		re_mat[i][i] = 1;
	}
	while (n > 0) {
		if (n % 2 == 1) {
			re_mat = re_mat * a;
		}
		n /= 2;
		a = a * a;
	}
	return re_mat;
}

void print(const Matrix& matrix) {
	ll size = matrix.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	Matrix matrix(n, vector<ll>(n));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	print(power(matrix, k));

	return 0;
}