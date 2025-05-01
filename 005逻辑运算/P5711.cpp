/**
 * https://www.luogu.com.cn/problem/P5711
 *
 * @File:   p5711.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2023-12-08
 *
 */
#include <iostream>

using namespace std;

int main(void)
{
    int n, out;

    scanf("%d", &n);

    if (!(n % 400) || (!(n % 4) && (n % 100)))
        out = 1;
    else
        out = 0;
    printf("%d\n", out);
    return 0;
}
