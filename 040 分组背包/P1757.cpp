#include <bits/stdc++.h>
using namespace std;

int a[110][1010] = {{0}};
int b[110][1010] = {{0}};
int c[110] = {0};
int dp[1010] = {0};

int main(void)
{
	int m, n, x;

	cin >> m >> n;
	x = 0;

	for (int i = 1; i <= n; i++) {
		int ai, bi, t;
		cin >> ai >> bi >> t;
		x = max(x, t);
		c[t]++;
		a[t][c[t]] = ai;
		b[t][c[t]] = bi;
	}

	for (int i = 1; i <= x; i++) {  // 遍历每一个分组
		for (int j = m; j >= 0; j--) {
			for (int l = 1; l <= c[i]; l++) { // 遍历当前分组中的每个物品
				if (j >= a[i][l])
					dp[j] = max(dp[j], dp[j - a[i][l]] + b[i][l]);
			}
		}
	}

	cout << dp[m] << endl;
	return 0;
}