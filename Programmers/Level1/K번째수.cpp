#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>solution(vector<int> arr, vector<vector<int> > commands) {
	vector<int>answer;
	vector<int>temp;
	for (int i = 0; i < commands.size(); i++)
	{
		for (int j = commands[i][0]-1; j <commands[i][1]-1 ; j++)
		{
			temp.push_back(arr[j]);
		}
		sort(temp.begin(), temp.end());
		answer.push_back(temp[commands[i][2] - 1]);
	}

	return answer;
}