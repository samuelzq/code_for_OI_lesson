#include <bits/stdc++.h>
using namespace std;

int dp[100005] = {0};


int main(void)
{
	int n, k;

	cin >> n >> k;
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {      // 先遍历背包限制
		for (int j = 1; j <= k; j++) {  // 然后遍历物品的种类
			if (i - j >= 0)
				dp[i] = (dp[i] + dp[i - j]) % 100003;
		}
	}

	cout << dp[n] << endl;
	return 0;
}