#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = 0;
	vector<int> lens;//길이 담을 벡터
	string temp, result;
	int count = 1;
	for (int i = 1; i <= s.length()/2; i++)
	{
		result = "";
		for (int j = 0; j < s.length(); j+=i)
		{
			temp = s.substr(j, i);
			if (i + j > s.length() || temp != s.substr(i + j, i)) {
				if (count != 1) {
					result += to_string(count);
				}
				result += temp;
				count = 1;
			}
			else {
				count++;
			}
		}
		lens.push_back(result.length());
	}
	if (s.length() == 1)answer = 1;
	else {
		answer = *min_element(lens.begin(), lens.end());
	}
	return answer;
}