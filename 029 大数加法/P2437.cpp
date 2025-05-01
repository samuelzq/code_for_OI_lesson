/**
 * https://www.luogu.com.cn/problem/P2437
 *
 * @File:   P2437.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-06-29
 *
 */
#include <iostream>
using namespace std;

const int LEN = 1024;
int f[1003][LEN] = {{0}};

void print(int a[])
{
    int i = LEN - 1;

    // 跳过无效位
    while (i && !a[i])
        i--;

    // 输出有效的数字
    for (; i >= 0; --i)
        putchar(a[i] + '0');

    putchar('\n');
}

void add(int a[], int b[], int c[])
{
    int ca = 0;

    // 大数加法实现中，一般令数组的最大长度 LEN 比可能的输入大一些
    // 然后略去末尾的几次循环，这样一来可以省去不少边界情况的处理
    // 因为实际输入不会超过 1000 位，故在此循环到 LEN - 1 = 1003 已经足够
    for (int i = 0; i < LEN - 1; ++i) {
        // 将相应位上的数带上进位相加
        c[i] = a[i] + b[i] + ca;
        if (c[i] >= 10) {
            // 进位
            ca = 1;
            c[i] -= 10;
        } else {
            ca = 0;  // 注意：进位是0
        }
  }
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);

    f[0][0] = f[1][0] = 1;
    for (int i = 2; i <= n - m; i++)
        add(f[i - 2], f[i - 1], f[i]);
    print(f[n - m]);
    return 0;
}
