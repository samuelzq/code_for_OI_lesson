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

int dp[30003] = {0};
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
		for (int j = n; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}