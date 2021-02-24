#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	//1´Ü°è
	for (int i = 0; i < new_id.length(); i++)
	{
		if ('A' <= new_id[i] && 'Z' >= new_id[i])
			new_id[i] = (new_id[i] - 'A')+'a';
	}
	//second
	int i = 0;
	while(i<new_id.length())
	{
		if (new_id[i] >= 'a'&&new_id[i] <= 'z') {
			i++;
			continue; 
		}
		else if (new_id[i] >= '0'&&new_id[i] <= '9') {
			i++;
			continue;
		}
		else if (new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_') {
			i++;
			continue;
		}
		new_id.erase(new_id.begin() + i, new_id.begin() + i + 1);
	}
	//third
	int first_idx, last_idx;
	i = 0;
	while (i<new_id.length()) {
		if (i + 1 < new_id.length() && new_id[i] == '.'&&new_id[i] == new_id[i + 1]) {
			new_id.erase(new_id.begin() + i, new_id.begin() + i + 1);
			continue;
		}
		i++;
	}
	//fourth
	while (!new_id.empty()&&(new_id[0] == '.'||new_id[new_id.length() - 1] == '.')) {
		if (new_id[0] == '.') {
			new_id.erase(new_id.begin(), new_id.begin() + 1);
			if (new_id.empty())
				continue;
		}
		if (new_id[new_id.length() - 1] == '.')
			new_id.erase(new_id.end() - 1, new_id.end());
	}
	//fifth
	if (new_id.empty())
		new_id.push_back( 'a');
	//sixth
	if (new_id.length() >= 16) {
		new_id.erase(new_id.begin() + 15, new_id.end());
	}
	if (new_id[new_id.length() - 1] == '.')
		new_id.erase(new_id.end() - 1, new_id.end());
	//seventh
	while (new_id.length() <= 2) {
		new_id.push_back(new_id[new_id.length() - 1]);
	}
	answer = new_id;
	return answer;
}

int main() {
	solution("abcdefghijklmn.p");
	return 0;
}