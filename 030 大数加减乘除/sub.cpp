#include <cstdio>
#include <cstring>

static const int LEN = 1004;

int a[LEN] = {0}, b[LEN] = {0}, c[LEN] = {0};

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

void sub(int a[], int b[], int c[])
{
    int s = 0;
    for (int i = 0; i < LEN - 1; ++i) {
        c[i] = a[i] - s - b[i];  // 每一位首先减去可能的借位，然后再减去减数对应的值
        if (c[i] < 0) { // 检查是否需要向高位借位
            s = 1;
            c[i] += 10;
        } else {
            s = 0;
        }
    }
}

int main()
{
    read(a);
    read(b);

    sub(a, b, c);
    print(c);

    return 0;
}
