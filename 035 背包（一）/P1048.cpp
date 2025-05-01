/**
 * https://www.luogu.com.cn/problem/P1048
 *
 * @File:   P1048.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-09-03
 *
 **/
#include <bits/stdc++.h>
using namespace std;

#define N     110
int dp[N][1010] = {{0}};
int v[N] = {0};
int w[N] = {0};


int main(void)
{
	int m, t;

	cin >> t >> m;
	for (int i = 1; i <= m; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= t; j++) {
			if (j < w[i]) { // 时间不够用，无法采
				dp[i][j] = dp[i - 1][j];
			} else { // 时间够用，在取和不取之间选最大的
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}
		}
	}

	cout << dp[m][t] << endl;
	return 0;
}
