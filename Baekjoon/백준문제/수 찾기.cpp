#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//ÀÌºĞÅ½»ö
int check(vector<int>arr, int start,int end,int target) {
	if (start > end)return 0;
	int mid = (start + end) / 2;
	if (arr[mid] == target)
		return 1;
	else if (arr[mid] < target)
		return check(arr, mid+1, end, target);
	else
		return check(arr,start,mid-1, target);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int arr_size, test_size;
	vector<int>arr;
	cin >> arr_size;
	int temp;
	for (int i = 0; i < arr_size;i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	cin >> test_size;
	for (int i = 0; i < test_size; i++)
	{
		cin >> temp;
		cout << check(arr, 0, arr.size() - 1, temp)<<"\n";
	
	}

	return 0;
}