#include <bits/stdc++.h>
using namespace std;
long long int dp[10000007] = {0};
int tt[10004], vv[10004];

int main(void)
{
	int t, m;

	cin >> t >> m;
	for (int i = 1; i <= m; i++)
		cin >> tt[i] >> vv[i];

	for (int i = 1; i <= m; i++) {
		for (int j = tt[i]; j <= t; j++) {
			dp[j] = max(dp[j], dp[j - tt[i]] + vv[i]);
		}
	}

	cout << dp[t] << endl;
	return 0;
}