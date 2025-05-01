#include <iostream>

using namespace std;

int a[105][105], b[105][105];

int main(void)
{
    int n, m;

    cin >> n >> m;

	// 接收第一个二维数组的内容
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

	// 接收第二个二维数组的内容
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

	// 输出两个二维数组之和
    for (int i = 0; i < n; i++)
    {
        cout << a[i][0] + b[i][0];
        for (int j = 1; j < m; j++)
            cout << ' ' << a[i][j] + b[i][j];
        cout << endl;
    }
    return 0;
}
