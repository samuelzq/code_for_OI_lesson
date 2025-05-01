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
int dp[1010] = {{0}};
int v[N] = {0};
int w[N] = {0};


int main(void)
{
	int m, t;

	cin >> t >> m;
	for (int i = 1; i <= m; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	cout << dp[t] << endl;
	return 0;
}
