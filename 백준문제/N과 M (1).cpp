#include <iostream>
#include <vector>

using namespace std;
int n, m;

void repeat(vector<int> v, int arr[]) {
	if (v.size() == m) { //길이가 M일 경우
		for (int i = 0; i < m; i++)
		{
			cout << v[i] <<" ";
		}
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] != 1) { //원소 사용 여부 확인
			v.push_back(i);
			arr[i] = 1;//사용했음을 체크
			repeat(v, arr);
			arr[i] = 0;//사용했음 해제
			v.pop_back();
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> answer;
	int *arr = new int[n+1];
	arr[0] = 1;//사용하지 않을 것이기에 미리 체크해놓음.
	repeat(answer,arr);


	return 0;
}