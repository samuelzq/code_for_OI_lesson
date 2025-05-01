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
int b[LEN] = {0};
int c[2 * LEN] = {0};

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

void mul(int a[], int b[], int c[])
{
    for (int i = 0; i < LEN - 1; i++) {
        // 这里直接计算结果中的从低到高第 i 位，且一并处理了进位
        // 第 i 次循环为 c[i] 加上了所有满足 p + q = i 的 a[p] 与 b[q] 的乘积之和
        // 这样做的效果和直接进行上图的运算最后求和是一样的，只是更加简短的一种实现方式
        for (int j = 0; j <= i; j++)
            c[i] += a[j] * b[i - j];

        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

void mul2(int a[], int b[], int c[])
{
    // 遍历两个数的每一位
    for (int i = 0; i < LEN - 1; i++) {
        for (int j = 0; j < LEN - 1; j++) {
            // 相乘，并加上之前的结果（进位）
            int p = a[i] * b[j];
            int s = p + c[i + j];

            // 处理进位
            c[i + j] = s % 10;
            c[i + j + 1] += s / 10;
        }
    }
}

int main()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    printf("请输入第一个大数a：");
    read(a);
    printf("请输入第二个大数b：");
    read(b);
    mul2(a, b, c);
    printf("a X b = ");
    print(c);
    return 0;
}
