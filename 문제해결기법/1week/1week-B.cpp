#include <iostream>
 
using namespace std;

float calMedian(int arr[], int d) {
	int med_count = 0;
	float median;
	if (d % 2 != 0) {
		for (int i = 0; i < 201; i++)
		{
			med_count = med_count + arr[i];
			if (med_count > d / 2) {
				median = i;
				break;
			}
		}
	}
	else {
		float fc = 0, sc = 0;
		for (int i = 0; i < 201; i++)
		{
			med_count = med_count + arr[i];
			if (med_count >= d / 2 && fc == 0) {
				fc = i;
			}
			if (med_count >= (d / 2 )+ 1 && sc == 0) {
				sc = i;
				median = float((fc + sc) / 2) ;
				break;
			}
		}
	}
	return median;
}


int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, d;
		cin >> n >> d;
		int *expenditure = new int[n];
		for (int i = 0; i < n; i += 2)
		{
			expenditure[i] = 0;
			expenditure[i + 1] = 0;
		}
		if (n % 2 != 0) {
			expenditure[n - 1] = 0;
		}
		int cntArray[201] = { 0, };
		int count = 0, temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			expenditure[i] = temp;
		}
		for (int i = 0; i < d; i++)
		{
			cntArray[expenditure[i]] = cntArray[expenditure[i]] + 1;
		}

		for (int i = d; i < n; i++)
		{
			float median = calMedian(cntArray, d);
			if (median * 2 <= expenditure[i]) {
				count++;
			}
			cntArray[expenditure[i - d]] = cntArray[expenditure[i - d]] - 1;
			cntArray[expenditure[i]] = cntArray[expenditure[i]] + 1;
		}
		cout << count << "\n";
	}
	return 0;
}
