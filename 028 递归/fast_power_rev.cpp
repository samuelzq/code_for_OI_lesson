#include <stdio.h>

// 递归快速幂算法
long long fast_power_recursive(long long a, long long b) {
    if (b == 0) {
        // 基本情况：任何数的0次幂都是1
        return 1;
    } else if (b == 1) {
        // 基本情况：直接返回底数
        return a;
    } else {
        // 递归计算 a 的 (b / 2) 次幂
        long long temp = fast_power_recursive(a, b / 2);
        // 如果b是奇数，则乘以a
        if (b % 2 == 1) {
            return temp * temp * a;
        } else {
            // 如果b是偶数，则直接平方
            return temp * temp;
        }
    }
}

int main() {
    long long a, b;

    printf("请输入基数 a 和指数 b: ");
    scanf("%lld %lld", &a, &b);

    long long result = fast_power_recursive(a, b);

    printf("%lld 的 %lld 次幂是 %lld\n", a, b, result);

    return 0;
}
