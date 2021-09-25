#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string>win_person;


bool search_win(string name) {
	
	vector<string>::iterator it;

	it = find(win_person.begin(), win_person.end(), name);
	if (it == win_person.end())
		return false;
	else
		return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool not_iron = false;
	int N, P, win, lose, standard, score=0;
	cin >> N >> P >>win>>lose>>standard;

	string name, result;

	for (int i = 0; i < P; i++)
	{
		cin >> name >> result;
		if (result == "W")
			win_person.push_back(name);
	}

	while (N--) {
		cin >> name;
		if (!not_iron) {
			if (search_win(name)) {
				score += win;
				if (score >= standard)
					not_iron = true;
			}
			else {
				score -= lose;
				if (score < 0)
					score = 0;
			}
		}
	}


	if (not_iron)
		cout << "I AM NOT IRONMAN!!\n";
	else
		cout << "I AM IRONMAN!!\n";
	

	return 0;
}