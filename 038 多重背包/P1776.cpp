#include <bits/stdc++.h>
using namespace std;

int dp[40004] = {0};
int v[110], w[110], m[110];

int main(void)
{
	int n, l;

	cin >> n >> l;

	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i] >> m[i];

	for (int i = 1; i <= n; i++) {
		for (int j = l; j >= w[i]; j--) {
			for (int k = 1; k <= m[i] && k * w[i] <= j; k++) {
				dp[j] = max(dp[j], dp[j - w[i] * k] + v[i] * k);
			}
		}
	}

	cout << dp[l] << endl;
	return 0;
}