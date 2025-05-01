/**
 * https://www.luogu.com.cn/problem/P1387
 *
 * @File:   P1387.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-08-07
 *
 **/
#include <bits/stdc++.h>
using namespace std;

#define N 200
int a[N][N] = {{0}};
int b[N][N] = {{0}};

int main(void)
{
	int n, m, ans;

	cin >> n >> m;

	// 接收数据并计算二维前缀和
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
		}
	}

	ans = 0;
	for (int l = min(n, m); l > 0; l--) { // 枚举矩形可能的边长
		for (int i = l; i <= n; i++) {
			for (int j = l; j <= m; j++) {
				// 利用前缀和求正方形内1的个数
				if (b[i][j] - b[i - l][j] - b[i][j - l] + b[i - l][j - l] == l *  l) { // 如果全为11
					ans = l;
					break;
				}
			}
			if (ans > 0)
				break;
		}
		if (ans > 0)
			break;
	}

	cout << ans << endl;
	return 0;
}
