#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int check = 0, idx= -1; 
	bool flag = true;
	int remember;
	for (int i = 0; i < skill_trees.size(); i++)
	{
		idx = -1, flag= true , remember = -1;
		for (int j = 0; j < skill.size(); j++)
		{
			check = 0;
			for (int k = 0; k < skill_trees[i].size(); k++)
			{
				if (skill_trees[i][k] == skill[j]) {
					if (idx > k) { //순서가 바뀌었을 경우
						flag = false;
						break;
					}
					else if (remember >= 0) { //앞의 스킬이 안나왔는데 그다음 스킬이 나온경우
						flag = false;
						break;
					}
					idx = k;
					check++;
					break;
				}
			}
			if (check == 0) {
				remember = j; 
			}
			if (!flag)
				break;
		}
		if (flag)
			answer++;
		

	}
	return answer;
}

//다른사람 풀이

int solution(string skill,vector<string>skill_trees){
	int answer = 0;
	for (int i = 0; i < skill_trees.size() ;i++)
	{
		vector<char> compare;
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			for (int k = 0; k < skill.size(); k++)
			{
				if (skill[k] == skill_trees[i][j]) {
					char temp = skill[k];
					compare.push_back(temp);
				}
			}
		}
		//먼저 배운 스킬을 순서대로 집어넣은 후
		//나중에 skill에 있는 순서와 비교한다
		bool flag = true;
		for (int c = 0; c < compare.size(); c++)
		{
			if (skill[c] != compare[c]) {
				flag = false;
				break;
			}

		}
		if (flag)
			answer++;
	}

	return answer;
}
