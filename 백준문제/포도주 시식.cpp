//2156
//dp»ç¿ë

#include <iostream>
#include <algorithm>

using namespace std;

long long wine[10000];
long long value[10000];

int max_wine(long long arr[], int size) {
	int answer= 0 ;
	for (int i = 0; i <= size; i++)
	{
		if (answer < arr[i])
			answer = arr[i];
	}
	return answer;
}


int main() {
	int n,temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value[i];
	}
	wine[0] = value[0];
	wine[1] = value[0] + value[1];
	for (int i = 2; i < n; i++)
	{
		wine[i] = max(value[i] + max_wine(wine, i-2), value[i] + value[i - 1] + max_wine(wine, i-3));
	}
	cout << *max_element(wine, wine + 10000);


	return 0;
}