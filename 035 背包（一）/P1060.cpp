/**
 * https://www.luogu.com.cn/problem/P1060
 *
 * @File:   P1060.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-09-03
 *
 **/
#include <bits/stdc++.h>
using namespace std;

int dp[30][30003] = {0};
int v[33] = {0};
int w[33] = {0};

int main(void)
{
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, p;
		cin >> a >> p;
		w[i] = a;
		v[i] = a * p;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (w[i] > j) // 当前预算不够
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	cout << dp[m][n] << endl;
	return 0;
}
