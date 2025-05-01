#include <iostream>
using namespace std;

#define N 100000    // 宏常量
bool isPrime[N];

void init(int n)
{
	// 初始化所有数为素数（true）
	for (int i = 0; i <= n; i++)
		isPrime[i] = true;

	isPrime[0] = isPrime[1] = false; // 0和1不是素数，标记它们  

	for (int i = 2; i * i <= n; i++) {// 从2开始标记非素数
		if (isPrime[i]) {	// 如果i是素数，那么i的平方到n的i的倍数都不是素数  
				for (int j = i * i; j <= n; j += i)
					isPrime[j] = false;
		}
	}
}

int main(void)
{
	int l, c, s, p;

	cin >> l;
	c = s = 0;

	init(l);
	p = 2;
	while (1) {
		if (isPrime[p]) {
			if (s + p <= l) {
				s += p;
				cout << p << endl;
				c++;
			} else {
				break;
			}
		}
		p++;
	}
	cout << c << endl;
	return 0;
}
