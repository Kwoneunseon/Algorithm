#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int months[] = {0,31,29,31,30,31,30,31,31,30,31,30,31 };
	string day[] = { "THU" ,"FRI","SAT","SUN","MON","TUE","WED"};
	int cnt = 0;
	for (int i = 1; i < a; i++)
	{
		cnt += months[i];
	}
	cnt += b;

	answer = day[cnt % 7];

	return answer;
}

int main() {
	solution(5,24);
	return 0;
}