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
					if (idx > k) { //������ �ٲ���� ���
						flag = false;
						break;
					}
					else if (remember >= 0) { //���� ��ų�� �ȳ��Դµ� �״��� ��ų�� ���°��
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
