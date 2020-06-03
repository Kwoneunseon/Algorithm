#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n, start, finish, x;
int solve(int v[], int x) {
	int answer = 0; 
	for (int i = 0; i <n ; i++)
	{
		int temp = pow(x, i);
		temp = temp % 1013;
		answer += (v[i] * temp) % 1013;
	}
	return answer % 1013;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int cnt = 0;
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cin >> start >> finish >> x;
		sort(arr, arr + n);
		vector<int>ans;
		ans.push_back(solve(arr, x));
		while (true) {
			if (next_permutation(arr, arr + n) == false) {
				break;
			}
			ans.push_back(solve(arr, x));
		}
		for (int i = 0; i < ans.size(); i++)
		{
			if (start <= ans[i] && ans[i] <= finish) {
				cnt++;
			}
		}
		cout << cnt<<"\n";
	}
	return 0;

}