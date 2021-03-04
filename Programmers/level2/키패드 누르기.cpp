#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int CL_x = 3, CL_y =0, CR_x= 3,CR_y= 2;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1) {
			CL_x = 0 , CL_y=0;
			answer.push_back('L');
		}
		else if (numbers[i] == 4) {
			CL_x = 1,CL_y = 0;
			answer.push_back('L');
		}
		else if (numbers[i] == 7) {
			CL_x = 2, CL_y = 0;
			answer.push_back('L');
		}
		else if (numbers[i] == 3) {
			CR_x=0, CR_y = 2;
			answer.push_back('R');
		}
		else if (numbers[i] == 6) {
			CR_x=1,CR_y = 2;
			answer.push_back('R');
		}
		else if (numbers[i] == 9) {
			CR_x = 2, CR_y = 2;
			answer.push_back('R');
		}
		else if (numbers[i] == 2) { //(0,1)
			int L_dis = pow((CL_x - 0), 2) + pow((CL_y - 1), 2);
			int R_dis = pow(CR_x - 0, 2) + pow((CR_y - 1), 2);

			if (L_dis == R_dis) {
				if (hand == "right") {
					answer.push_back('R');
				}
				else if (hand == "left")
					answer.push_back('L');
			}
			else if (L_dis < R_dis) {
				answer.push_back('L');
				CL_x = 0, CL_y = 1;
			}
			else {
				answer.push_back('R');
				CR_x = 0, CR_y = 1;
			}
		}
		else if (numbers[i] == 5) { //(1,1)
			int L_dis = pow((CL_x - 1), 2) + pow((CL_y - 1), 2);
			int R_dis = pow(CR_x - 1, 2) + pow((CR_y - 1), 2);

			if (L_dis == R_dis) {
				if (hand == "right") {
					answer.push_back('R');
				}
				else if (hand == "left")
					answer.push_back('L');
			}
			else if (L_dis < R_dis) {
				answer.push_back('L');
				CL_x = 1, CL_y = 1;
			}
			else {
				answer.push_back('R');
				CR_x = 1, CR_y = 1;
			}
		}
		else if (numbers[i] == 8) {//(2,1)
			int L_dis = pow((CL_x - 2), 2) + pow((CL_y - 1), 2);
			int R_dis = pow(CR_x - 2, 2) + pow((CR_y - 1), 2);

			if (L_dis == R_dis) {
				if (hand == "right") {
					answer.push_back('R');
				}
				else if (hand == "left")
					answer.push_back('L');
			}
			else if (L_dis < R_dis) {
				answer.push_back('L');
				CL_x = 2, CL_y = 1;
			}
			else {
				answer.push_back('R');
				CR_x = 2, CR_y = 1;
			}
		}
		else if (numbers[i] == 0) {//(3,1)
			int L_dis = pow((CL_x - 3), 2) + pow((CL_y - 1), 2);
			int R_dis = pow(CR_x - 3, 2) + pow((CR_y - 1), 2);

			if (L_dis == R_dis) {
				if (hand == "right") {
					answer.push_back('R');
				}
				else if (hand == "left")
					answer.push_back('L');
			}
			else if (L_dis < R_dis) {
				answer.push_back('L');
				CL_x = 3, CL_y = 1;
			}
			else {
				answer.push_back('R');
				CR_x = 3, CR_y = 1;
			}
		}
	
	
	}
	return answer;
}

int main() {
	int arr[11] = {1,2,3,4,5,6,7,8,9,0 };
	vector<int> numbers;
	for (int i = 0; i < 11; i++)
	{
		numbers.push_back(arr[i]);
	}
	cout << solution(numbers, "right");

	return 0;
}