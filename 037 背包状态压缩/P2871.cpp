/**
 * https://www.luogu.com.cn/problem/P2871
 *
 * @File:   P2871.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-09-09
 *
 **/
#include <bits/stdc++.h>
using namespace std;

#define N  3500
int w[N], d[N];
int dp[13000] = {0};

int main(void)
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> d[i];

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
	}
	cout << dp[m] << endl;
	return 0;
}