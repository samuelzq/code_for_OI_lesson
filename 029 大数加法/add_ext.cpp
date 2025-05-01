#include <iostream>
#include <cstring>

static const int LEN = 1004;

const int maxn = 1e7;
int a[LEN], b[LEN], c[LEN];

// 将数组a[]全部成员设成0
void clear(int a[])
{
    for (int i = 0; i < LEN; ++i)
        a[i] = 0;
}

// 读取大数
void read(int a[])
{
    char s[LEN + 1];

    // 首先将输入的大数作为字符串接收
    // 注意输入时首先输入的是最高位
    // 因此后面需要调换字符的顺序
    scanf("%s", s);

    // 解析刚刚接收的字符串
    // a[0]存放最低位的数字
    clear(a);

    int len = strlen(s);
    int i = len - 1;
    int k = 0;
    while (i >= 0) {
        int t = 0, p = 1;
        for (int j = 0; i >= 0 && j < 7; i--, j++) {
            t = t + (s[i] - '0') * p;
            p *= 10;
        }
        a[k++] = t;
    }
}

// 打印大数
void print(int a[])
{
    int i = LEN - 1;

    // 跳过无效位
    while (i && !a[i])
        i--;

    printf("%d", a[i--]);

    // 输出有效的数字
    for (; i >= 0; --i)
        printf("%07d", a[i]);

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
        if (c[i] >= maxn) {
            // 进位
            ca = 1;
            c[i] -= maxn;
        } else {
            ca = 0;  // 注意：进位是0
        }
  }
}

int main()
{
    read(a);
    read(b);
    add(a, b, c);
    print(c);

    return 0;
}

