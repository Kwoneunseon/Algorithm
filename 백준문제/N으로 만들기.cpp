#include <iostream>
#include <string>
#include <set>

using namespace std;

string n;
bool num_visted[11];

set<string> answer;

bool check(string a, string b) {
	//check은 b가 순서대로 잘 만들어지고 있는지 확인하는 함수.
	//a가 정답, b가 만들고 있는 문자
	int idx = 0;
	for (int i = 0; i < a.length() && idx < b.length(); i++)
	{
		if (a[i] == b[idx])
			idx++;
	}
	if (idx == b.length())
		return true;
	else
		return false;
}

void backTracking(int idx, string s, string process) {
	if (s.length() == n.length()) {
		//n이 만들어지면 set배열에 넣어줌
		//process를 넣는 이유 : 반복된 수가 있을 경우, 만들어지는 과정이 같을 수 있기 때문에
		answer.insert(process);
		return;
	}

	for (int i = 0; i < n.length(); i++)
	{
		if (num_visted[i])
			continue;
		if (check(n, n[i] + s)) {
			//오른쪽에 숫자를 적는 경우
			num_visted[i] = true;
			backTracking(idx + 1, n[i] + s, process + n[i] + s);
			num_visted[i] = false;
		}
		if (check(n, s + n[i])) {
			//왼쪽에 숫자를 적는 경우
			num_visted[i] = true;
			backTracking(idx + 1, s + n[i], process + s + n[i]);
			num_visted[i] = false;

		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n;
	backTracking(0, "","");
	if (answer.size())
		cout << answer.size();
	else
		cout << 1;
	return 0;
}