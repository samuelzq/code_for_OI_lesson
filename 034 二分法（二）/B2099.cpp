/**
 * https://www.luogu.com.cn/problem/B2099
 *
 * @File:   B2099.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-02-09
 *
 */
#include <bits/stdc++.h>

using namespace std;

int a[6][6];

int main(void)
{
    int m, n;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];

    cin >> m >> n;
    m--;
    n--;

    for (int i = 0; i < 5; i++)
    {
        int t = a[m][i];
        a[m][i] = a[n][i];
        a[n][i] = t;
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cout << a[i][j] << ((j != 4) ? ' ' : '\n');
    return 0;
}

