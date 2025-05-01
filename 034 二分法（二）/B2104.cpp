/**
 * https://www.luogu.com.cn/problem/B2104
 *
 * @File:   B2104.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-02-09
 *
 */
#include <bits/stdc++.h>

using namespace std;

int a[105][105], b[105][105];

int main(void)
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    for (int i = 0; i < n; i++)
    {
        cout << a[i][0] + b[i][0];
        for (int j = 1; j < m; j++)
            cout << ' ' << a[i][j] + b[i][j];
        cout << endl;
    }
    return 0;
}

