#include <bits/stdc++.h>
using namespace std;

#define N  10004
int p[N], t[N];
int dp[N] = {0};     // dynamic programming

int main(void)
{
	int m, n;

	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> t[i];

	for (int i = 1; i <= n; i++) {
		for (int j = t[i]; j <= m; j++) {
			dp[j] = max(dp[j], dp[j - t[i]] + p[i]);
		}
	}

	cout << dp[m] << endl;
	return 0;
}