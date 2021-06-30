#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int sum=0,cnt;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C')
			sum += 3;
		else if(s[i] == 'D' || s[i] == 'E' || s[i] == 'F')
			sum += 4;
		else if (s[i] == 'G' || s[i] == 'H' || s[i] == 'I')
			sum += 5;
		else if (s[i] == 'J' || s[i] == 'K' || s[i] == 'L')
			sum += 6;
		else if (s[i] == 'M' || s[i] == 'N' || s[i] == 'O')
			sum += 7;
		else if (s[i] == 'P' || s[i] == 'Q' || s[i] == 'R'||s[i]=='S')
			sum += 8;
		else if (s[i] == 'T' || s[i] == 'U' || s[i] == 'V')
			sum += 9;
		else if (s[i] == 'W' || s[i] == 'X' || s[i] == 'Y'||s[i]=='Z')
			sum += 10;

	}
	cout << sum;
	return 0;
}