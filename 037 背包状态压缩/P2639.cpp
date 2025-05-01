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

int dp[45010] = {0};
int s[550];

int main(void)
{
	int h, n;

	cin >> h >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];

	for (int i = 1; i <= n; i++) {
		for (int j = h; j >= s[i]; j--)
			dp[j] = max(dp[j], dp[j - s[i]] + s[i]);
	}
	cout << dp[h] << endl;
	return 0;
}