#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<char, char>mbti_map;

	//map을 사용하여 반대의 값들의 Key와 value에 넣어준다.
	mbti_map.insert({ 'E','I' });
	mbti_map.insert({ 'I','E' });
	mbti_map.insert({ 'S','N' });
	mbti_map.insert({ 'N','S' });
	mbti_map.insert({ 'F','T' });
	mbti_map.insert({ 'T','F' });
	mbti_map.insert({ 'P','J' });
	mbti_map.insert({ 'J','P' });

	string mbti, answer="";

	cin >> mbti;
	for (int i = 0; i < 4; i++)
	{
		answer.push_back(mbti_map[mbti[i]]);
	}
	cout << answer;
	
	return 0;
}