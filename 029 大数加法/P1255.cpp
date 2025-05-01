/**
 * https://www.luogu.com.cn/problem/P125
 *
 * @File:   P1255.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-06-29
 *
 */
#include <iostream>
using namespace std;

const int LEN = 2024;
int f[5001][LEN] = {{0}};


void add(int a[], int b[], int c[])
{
    int ca = 0;

    for (int i = 0; i < LEN - 1; ++i) {
        c[i] = a[i] + b[i] + ca;
        if (c[i] >= 10) {
            // 进位
            ca = 1;
            c[i] -= 10;
        } else {
            ca = 0;
        }
    }
}

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


int main(void)
{
    int n;

    cin >> n;

    f[0][0] = f[1][0] = 1;
    for (int i = 2; i <= n; i++)
        add(f[i - 1], f[i - 2], f[i]);
    print(f[n]);
    return 0;
}
