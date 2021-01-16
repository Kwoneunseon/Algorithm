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
