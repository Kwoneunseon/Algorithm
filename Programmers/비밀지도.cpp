//2020.09.04
#include <iostream>
#include<vector>
#include <string>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	string temp_vec;
	char *temp = new char[n];
	for (int i = 0; i < n; i++)//각 줄을 확인하기 위해
	{
		for (int j = n-1; j >=0; j--)
		{
			if (arr1[i] % 2 == 1) {
				arr1[i] = arr1[i]/2;
				arr2[i] = arr2[i] / 2;
				temp[j] = '#';
			}
			else if (arr2[i] %2 == 1) {
				arr1[i] = arr1[i] / 2;
				arr2[i] = arr2[i] /2;
				temp[j] = '#';
			}
			else {
				temp[j] = ' ';
				arr2[i] = arr2[i] / 2;
				arr1[i] = arr1[i] / 2;
			}
		}
		for (int i = 0; i < n; i++)
		{
			temp_vec.push_back(temp[i]);
		}
		answer.push_back(temp_vec);
		temp_vec.clear();
		
	}

	return answer;
}

int main() {
	int n = 6;
	vector<int> v1;
	vector<int>v2;
	int arr1[] = { 46,33,33,22,31,50};
	int arr2[] = { 27,56,19,14,14,10 };
	for (int i = 0; i < n; i++)
	{
		v1.push_back(arr1[i]);
		v2.push_back(arr2[i]);
	}
	vector<string> ans = solution(n, v1, v2);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}