#include <iostream>
#include <vector>

using namespace std;

int get_Rootgate(vector<int>& gate, int a) {
	if (gate[a] == a)return a;
	return gate[a] = get_Rootgate(gate,gate[a]);
}

//a는 main함수 안에서 구했기 때문에 다시 구하지 않는다.
void Union_gate(vector<int>& gate, int a, int b) {
	b = get_Rootgate(gate, b);
	gate[a] = b;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int G, P, g,count = 0;
	bool flag = true;
	cin >> G >> P;
	vector<int>plane(P+1);
	vector<int>gate(G + 1);
	for (int i = 0; i <= G; i++)
	{
		gate[i] = i;
	}

	for (int i = 0; i < P; i++)
	{
		cin >> plane[i];
		int Rootgate = get_Rootgate(gate, plane[i]);

		if (Rootgate != 0 && flag) {
			Union_gate(gate, Rootgate, Rootgate - 1);
			count++;
		}
		else {
			flag = false;
			continue;
		}
	}

	cout << count;

	return 0;
}