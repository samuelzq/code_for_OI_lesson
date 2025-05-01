#include <iostream>
using namespace std;

#define N 10005    // 宏常量
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
    int n;

    cin >> n;
    init(n);

	for (int i = 4; i <= n; i += 2) {
		for (int j = 2; j < i; j++) {
			if (isPrime[j] && isPrime[i - j]) {
				cout << i << '=' << j << '+' << i-j << endl;
				break;
			}
		}
	}
	return 0;
}