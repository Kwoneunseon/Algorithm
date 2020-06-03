#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class item {
public:
	string name;
	int start;
	int finish;

};
bool cmp(const item& i1, const item &i2) {
	if (i1.finish < i2.finish)
		return true;
	else if (i1.finish == i2.finish) {
		return i1.start < i2.start;
	}
	else
		return false;
}
int main(){
	int T;
	cin >> T;
	while (T--) {
		int n;
		item arr[10000];
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].name;
			cin >> arr[i].start;
			cin >> arr[i].finish;
		}
		sort(arr, arr + n, cmp);
		int count = 1, current = 0;
		for (int i = 1; i < n; i++)
		{
			if (arr[i].start >= arr[current].finish) {
				current = i;
				count = count + 1;
			}
		}
		cout << count << "\n";
	}
	return 0;
}