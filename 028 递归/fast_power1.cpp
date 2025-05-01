#include <stdio.h>

// 快速幂算法，计算 a 的 b 次幂
long long fast_power(long long a, long long b) {
    long long result = 1; // 初始化结果为1
    while (b > 0) {
        // 如果b是奇数，则乘以a
        if (b & 1) {
            result = result * a;
        }
        // a平方
        a = a * a;
        // b右移一位，相当于b除以2
        b >>= 1;
    }
    return result;
}

int main() {
    long long a, b;

    printf("请输入基数 a 和指数 b: ");
    scanf("%lld %lld", &a, &b);

    long long result = fast_power(a, b);

    printf("%lld 的 %lld 次幂是 %lld\n", a, b, result);

    return 0;
}
