#include <iostream>
using namespace std;

class location {
public:
	int x, y;
	location() {
		x = 0, y = 0;
	}
	location(int a, int b) {
		this->x = a;
		this->y = b;
	}
};

void quickSort(location *data, int start, int end) {
	if (start >= end)
		return;
	int key = start;
	int  i = start + 1, j = end;
	location temp;
	while (i <=j) {
		while (i <= end && data[i].x <= data[key].x) {
			if (data[i].x == data[key].x &&data[i].y> data[key].y) {
				break;
			}
			i++;
		}
		while (j > start&&data[j].x >= data[key].x) {
			if (data[j].x == data[key].x &&data[j].y < data[key].y) {
				break;
			}
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,temp_x,temp_y;
	cin>>n;
	location* arr = new location[n];
	for (int i = 0; i < n; i++)
	{
		cin >> temp_x >> temp_y;
		location temp = location(temp_x, temp_y);
		arr[i] = temp;
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].x << " " << arr[i].y << "\n";
	}

	return 0;
}