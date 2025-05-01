#include <iostream>

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
	    long long int num;
	    scanf("%lld", &num);

	    // 尝试从2开始分解num
	    for (long long int i = 2; i * i <= num; i++) {
	        // 如果i是num的因数
	        while (num % i == 0) {
                printf("%lld ", i); // 打印质因数

	            num /= i;         // 继续分解剩下的数
	        }
	    }

	    // 如果num大于1，那么num是一个质数
	    if (num > 1)
	        printf("%lld ", num);

	    printf("\n");
	}
    return 0;
}
