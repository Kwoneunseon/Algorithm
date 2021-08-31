#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
	int height, weight;
};

int main() {
	int N,rank;
	cin >> N;
	vector<Person>p(N);
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].weight >> p[i].height;
	}

	for (int i = 0; i < N; i++)
	{
		rank = 1;
		for (int j = 0; j < N; j++)
		{
			if (p[i].height < p[j].height && p[i].weight < p[j].weight)
				rank++;
		}
		cout << rank << " ";
	}



	return 0;
}