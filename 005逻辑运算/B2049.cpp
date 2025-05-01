/**
 * https://www.luogu.com.cn/problem/B2049
 *
 * @File:   b2049.cpp
 * @Author: Lao Zhang samuelzhang77@yahoo.com
 * @Date:   2023-11-12
 *
 */
#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c, out;

    scanf("%d %d %d", &a, &b, &c);

    if (a > b)
        out = a;
    else
        out = b;

    if (out < c)
        out = c;

    printf("%d\n", out);
    return 0;
}
