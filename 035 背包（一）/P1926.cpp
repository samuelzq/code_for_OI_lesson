/**
 * https://www.luogu.com.cn/problem/P1926
 *
 * @File:   P1926.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-09-06
 *
 **/
#include <bits/stdc++.h>
using namespace std;

int p[15], h[15], v[15];
int dp[15][200] = {0};    // 刷题最大数量

int main(void)
{
	int n, m, k, r, cnt;

	cin >> n >> m >> k >> r;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= m; i++)
		cin >> h[i];

	for (int i = 1; i <= m; i++)
		cin >> v[i];

	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= k; j++)
			dp[i][j] = 0x3f3f3f3f;

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= k; j++) {
			if (j < v[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + h[i]);
		}
	}
	//cout << dp[m][k] << endl;

	sort(p, p + n);
	r = r - dp[m][k];
	cnt = 0;
	for (int i = 1; i <= n && p[i] <= r; i++) {
		cnt++;
		r -= p[i];
	}
	cout << cnt << endl;
	return 0;
}
