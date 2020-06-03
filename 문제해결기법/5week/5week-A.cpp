#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int front = 0, rear = s.length() - 1;
		bool check = true;
		while (front < rear) {
			char front_chr = s[front], rear_chr = s[rear];
			if (!(('A' <= front_chr && front_chr <= 'Z') || ('a' <= front_chr && front_chr <= 'z'))) {
				front++;
				continue;
			}
			if (!(('A' <= rear_chr && rear_chr <= 'Z') || ('a' <= rear_chr && rear_chr <= 'z'))) {
				rear--;
				continue;
			}
			if ('A' <= front_chr && front_chr <= 'Z') {
				front_chr = 'a' + (front_chr - 'A');
			}
			if ('A' <= rear_chr && rear_chr <= 'Z') {
				rear_chr = 'a' + (rear_chr - 'A');
			}
			if (front_chr != rear_chr) {
				check = false;
				break;
			}
			front++, rear--;

		}
		if (check) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}