using namespace std;

// w * h - (w + h - gcd)

int gcd(int a, int b) {
	int value = 1;
	if (a < b) {
		int temp = b;
		b = a;
		a = temp;
	}
	//항상 a가 큼
	for (int i = 1; i <= b; i++)
	{
		if (a % i == 0 && b %i == 0)
			value = i;

	}
	return value;

}
long long soulution(int w, int h){
	long long answer = 1;

	answer = w * h - (w + h - gcd(w, h));

	return answer;
}

//gcd구하는 다른 방법들
int gcd_1(int w, int h) {
	int gcd = 1;
	for (int i = (w<h?w:h); i >= 0; i--)
	{
		if (w %i == 0 && h % i == 0) {
			gcd = i;
			break;
		}
	}
	return gcd;
}

int gcd_2(int w, int h) {
	if (w == 0)return h;
	return (h%w, w);
}