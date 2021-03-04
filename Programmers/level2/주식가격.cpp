//2020.09.04
//https://dvpzeekke.tistory.com/15 참고
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int size = prices.size();
	for (int i = 0; i < size-1; i++)
	{
		int count = size - 1 - i;//가장 최대로 나올 수 있는 시간을 구함.
		for (int j =i+1; j < size; j++)
		{
			if (prices[i] > prices[j]) {
				count = j - i;
				break;
			}
		}
		answer.push_back(count);
	}
	answer.push_back(0);
	return answer;
}

int main() {
	int temp;
	int arr[] = { 1,2,3,2,3 };
	vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(arr[i]);
	}
	vec = solution(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "  ";
	}
	return 0;
}