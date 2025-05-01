/**
 *
 * @File:   P1706_c.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-11
 *
 */
#include <stdio.h>

#define MAXN 10 // n 的最大值为 9，数组大小设置为 10 (索引 1-9)

int n;
int currentPermutation[MAXN];
int used[MAXN];

//参数 k: 表示当前正在确定的排列中的位置索引（从 0 开始）
void generatePermutations(int k) {
    if (k == n) {
        for (int i = 0; i < n; ++i) {
            printf("%5d", currentPermutation[i]);
        }
        printf("\n");
        return;
    }

    // 循环遍历数字 1 到 n
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            currentPermutation[k] = i;
            used[i] = 1;
            generatePermutations(k + 1);
            used[i] = 0; // 回溯
        }
    }
}

int main() {
    scanf("%d", &n);

    // 初始化 used 数组
    for (int i = 0; i <= n; ++i) {
        used[i] = 0;
    }

    generatePermutations(0);

    return 0;
}
