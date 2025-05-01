/**
 * https://www.luogu.com.cn/problem/P2639
 *
 * @File:   P2639.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-09-06
 *
 **/
#include <bits/stdc++.h>
using namespace std;

int dp[502][45010] = {0};
int s[550];

int main(void)
{
	int h, n;

	cin >> h >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= h; j++) {
			if (j < s[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s[i]] + s[i]);
		}
	}
	cout << dp[n][h] << endl;
	return 0;
}
