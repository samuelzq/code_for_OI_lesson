/**
 *
 * @File:   multi_single.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-07-07
 *
 */
#include <cstdio>
#include <cstring>

static const int LEN = 1004;

int a[LEN] = {0};

void read(int a[])
{
    static char s[LEN + 1];
    scanf("%s", s);

    int len = strlen(s);
    for (int i = 0; i < len; i++)
        a[len - i - 1] = s[i] - '0';
}

void print(int a[])
{
    int i;
    for (i = LEN - 1; i >= 1; i--)
        if (a[i] != 0)
            break;

    for (; i >= 0; i--)
        putchar(a[i] + '0');
    putchar('\n');
}

void mul_single(int a[], int b, int c[])
{
    int ca, p;
    ca = p = 0;

    for (int i = 0; i < LEN - 1; i++) {
        // 直接把 a 的第 i 位数码乘以乘数，再加上进位值
        p = a[i] * b + ca;

        if (p >= 10) {
            // 处理进位
            // p / 10 即除法的商数成为进位的增量值
            ca = p / 10;
            // 而 p % 10 即除法的余数成为在当前位留下的值
            p = p % 10;
        } else {
            ca = 0;
        }
        c[i] = p; // 记录下当前数位上的数值
    }
}

int main()
{
    int b;
    memset(a, 0, sizeof(a));

    printf("请输入第一个大数a：");
    read(a);
    printf("请输入小数b：");
    scanf("%d", &b);
    mul_single(a, b, a);
    printf("a X b = ");
    print(a);
    return 0;
}
