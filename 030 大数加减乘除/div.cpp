#include <cstdio>
#include <cstring>

static const int LEN = 1004;

int a[LEN] = {0}, b[LEN] = {0};

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
    for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0)
        break;

    for (; i >= 0; --i)
        putchar(a[i] + '0');
    putchar('\n');
}

void div(int a[], int b, int c[], int *d)
{
    int t = 0;

    for (int i = LEN - 1; i >= 0; i--) {
        t = t * 10 + a[i];

        if (t >= b) {
            int q = t / b;
            t %= b;
            c[i] = q;
        } else {
            c[i] = 0;
        }
    }
    *d = t;
}

int main(void)
{
    int bb, dd;
    read(a);
    scanf("%d", &bb);
    div(a, bb, b, &dd);
    print(b);
    return 0;
}
