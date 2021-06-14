#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	string sa, sb;
	int answer; //sa가 크면 1 sb가 크면 2;
	cin >> a >> b;
	sa = to_string(a);
	sb = to_string(b);
	char temp = sa[0];
	sa[0] = sa[2];
	sa[2] = temp;
	temp = sb[0];
	sb[0] = sb[2];
	sb[2] = temp;
	a = stoi(sa);
	b = stoi(sb);
	
	cout << max(a, b);
	return 0;
}