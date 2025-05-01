/**
 *
 * @File:   comb2.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-13
 *
 */
#include <stdio.h>

// 计算 x 中 1 的个数
int count_ones(int x) {
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}

// 打印 bits 中为 1 的位置对应的元素
void print_combination(int bits, int n) {
    for (int i = 0; i < n; i++) {
        int pos = n - i - 1; // 高位对应前面元素
        if ((bits >> pos) & 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

void simple_combination(int n, int k) {
    int upper = (1 << n) - 1;
    for (int bits = upper; bits >= 0; bits--) {
        if (count_ones(bits) == k) {
            print_combination(bits, n);
        }
    }
}

int main() {
    int n = 5, k = 3;
    simple_combination(n, k);
    return 0;
}
