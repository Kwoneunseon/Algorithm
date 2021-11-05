#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	string number;
	int count = 0;
	cin >> number;
	while (number.length()>1) {
		int num_length = number.length();
		count++;
		int new_num=0;
		for (int i = 0; i < num_length; i++)
		{
			new_num += (number[i] - '0');
		}
		number = to_string(new_num);
	}
	//변환 과정의 개수 출력
	cout << count << "\n";
	//3의 배수인지 아닌지 출력
	if (stoi(number) % 3 == 0)
		cout << "YES";
	else
		cout << "NO";



	return 0;
}