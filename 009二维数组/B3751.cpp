#include <bits/stdc++.h>

using namespace std;

char a[55][55];

int main(void)
{
    int n, m, k;

	// 接收输入，并初始化矩形（全部填充'.'）
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = '.';

    for (int i = 0; i < k; i++)
    {
        int x, y;
        char c, d;
        cin >> x >> y >> c >> d;

        if (d == 'R')
        { // 向右刷，列索引增加
            for (int i = y; i <= m; i++)
                a[x][i] = c;
        }
        else if (d == 'L')
        { // 向左刷，列索引递减
            for (int i = y; i >= 1; i--)
                a[x][i] = c;
        }
        else if (d == 'U')
        { // 向上刷，行索引递减
            for (int i = x; i >= 1; i--)
                a[i][y] = c;
        }
        else if (d == 'D')
        { // 向下刷，行索引递增
            for (int i = x; i <= n; i++)
                a[i][y] = c;
        }
    }

    // 输出修改后的内容
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}
