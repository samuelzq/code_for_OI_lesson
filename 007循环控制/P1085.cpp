#include <iostream>

using namespace std;

int main(void)
{
    int d, h;

    h = 0;  // 每周中一天花在学习上的时间的最大值
    d = 0;  // 一周中学习时间最长的那一天
    for (int i = 1; i <= 7; i++)
    {
        int a, b;
        cin >> a >> b;
        if (h < a + b)
        {
            h = a + b;
            d = i;
        }
    }
    if (h > 8)
        cout << d << endl;
    else
        cout << 0 << endl;
    return 0;
}
