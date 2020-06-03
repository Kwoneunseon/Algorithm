#include <iostream>
#include <string>
using namespace std;

int m, n;

int haming_distance(string codeword, string sub) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (codeword[i] != sub[i])
			count++;
	}
	return count;
}
int find_minimum(string codeword[], string sub) {
	int min_idx, min_hd, hd;
	min_hd = n + 1;
	min_idx = -1;
	for (int i = 0; i < m; i++)

	{
		hd = haming_distance(codeword[i], sub);
		if (min_hd > hd) {
			min_hd = hd;
			min_idx = i;
		}
	}
	return min_idx;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int  bitlen, cnt;//�˹ٺ� ������ �ڵ���� ��Ʈ��;
		//bitlen : ���ڵ��� ��Ʈ�� ����, ��Ʈ�� �Է�
		cin >> m >> n;
		string temp;
		string codeword[26], bitstream;
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			codeword[i] = temp;
		}
		cin >> bitlen >> bitstream;
		cnt = bitlen / n;
		string sub;
		for (int i = 0; i < cnt; i++)
		{
			sub = bitstream.substr(i*n, (i + 1)*n);
			cout << char('A' + find_minimum(codeword, sub));

		}
		cout << "\n";
	}
	return 0;
}