//2020.09.04
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> stages) {
	vector<int> answer;
	int *check = new int[n];
	double *fail = new double[n];
	for (int i = 0; i < n; i++)
	{
		check[i] = 0;
	}
	for (int i = 0; i < stages.size(); i++)
	{
		if (stages[i] - 1 > n)
			continue;
		check[stages[i] - 1]++;
	}
	int person = stages.size();
	for (int i = 0; i < n; i++)
	{	
		if (person == 0)
			break;
		fail[i] = (double)check[i] / (double)person;
		person = person - check[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		double max =-1;
		int max_idx=0;
		for (int j = 0; j < n; j++)
		{
			if (max < fail[j]) {
				max = fail[j];
				max_idx = j;
			}
		}
		fail[max_idx] = -1;
		answer.push_back(max_idx+1);
	}


	return answer;
}

int main() {
	int n = 4;
	vector<int> vec;
	vector<int>ans;
	int arr[] = {4,4,4,4 };
	for (int i = 0; i < 4; i++)
	{
		vec.push_back(arr[i]);
	}
	ans = solution(n, vec);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}


	return 0;
}