/**
 * https://www.luogu.com.cn/problem/P2430
 *
 * @File:   P2430.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-09-06
 *
 **/
#include <bits/stdc++.h>
using namespace std;

#define N 110
int v[N], p[N], q[N];
int dp[5050] = {0};

int main(void)
{
	int n, m, k, w, l;

	cin >> k >> w >> m >> n;

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		v[i] = t * w / k;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = v[a];
		q[i] = b;
	}

	cin >> l;
	for (int i = 1; i <= m; i++) {
		for (int j = l; j >= p[i]; j--) {
			dp[j] = max(dp[j], dp[j - p[i]] + q[i]);
		}
	}
	cout << dp[l] << endl;
	return 0;
}
