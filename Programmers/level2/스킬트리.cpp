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

//�ٸ���� Ǯ��

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
		//���� ��� ��ų�� ������� ������� ��
		//���߿� skill�� �ִ� ������ ���Ѵ�
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
