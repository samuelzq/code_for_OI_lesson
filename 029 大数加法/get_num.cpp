#include <iostream>
#include <cstring>

static const int LEN = 1004;

int a[LEN], b[LEN];

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
    for (int i = 0; i < len; ++i)
        a[len - i - 1] = s[i] - '0';  // 注意需要将字符串中数字字符颠倒过来
}

// 打印大数
void print(int a[])
{
    int i = LEN - 1;

    // 跳过无位
    while (!a[i])
        i--;

    // 输出有效的数字
    for (; i >= 0; --i)
        putchar(a[i] + '0');

    putchar('\n');
}

int main()
{
    read(a);
    print(a);

    return 0;
}
