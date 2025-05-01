/**
 * https://www.luogu.com.cn/problem/P2925
 *
 * @File:   P2925.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-09-09
 *
 **/
#include <bits/stdc++.h>
using namespace std;

int h[5003];
int dp[50004] = {0};

int main(void)
{
	int c, n;

	cin >> c >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	for (int i = 1; i <= n; i++) {
		for (int j = c; j >= h[i]; j--)
			dp[j] = max(dp[j], dp[j - h[i]] + h[i]);
	}
	cout << dp[c] << endl;
	return 0;
}
