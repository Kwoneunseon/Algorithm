#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int solution(vector<vector<int>> triangle) {
	int answer = 0;
	vector<vector<int>>dp(triangle.size());
	dp[0].push_back(triangle[0][0]);
	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			int temp;
			if (j ==0) {
				temp = dp[i - 1][j];
			}
			else if(j==triangle[i].size()-1){
				temp = dp[i - 1][j-1];
			}
			else {
				temp = max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			dp[i].push_back(temp + triangle[i][j]);
		}
	}

	answer = *max_element(dp[triangle.size() - 1].begin(), dp[triangle.size()-1].end());
	return answer;
}
int main() {
	solution({ {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} });
}
