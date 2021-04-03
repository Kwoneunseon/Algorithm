//1139
//그리디
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char numbers[27];

int main() {
	int N,max_string_size=0;
	cin >> N;
	string *str = new string[N];
	vector<int>str_to_int;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		if (max_string_size < str[i].length())
			max_string_size = str[i].length();
	}
	int idx = 9;
	for (int i = 0; i <max_string_size ;i++)
	{
		for (int j= 0; j < N; j++)
		{
			if (str[j].length() > max_string_size-1-i) {
				if (numbers[str[j][i]-'A'] == NULL) {
					numbers[str[j][i] - 'A'] = idx+'0';
					idx--;
				}
			}
		}
	}

	//number로 바꾸기
	for (int i = 0; i < N; i++)
	{
		string temp="";
		for (int j = 0;  j < str[i].length();  j++)
		{
			temp += numbers[str[i][j] - 'A'];
		}
		str_to_int.push_back(stoi(temp));
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += str_to_int[i];
	}
	cout << sum;
	return 0;
}