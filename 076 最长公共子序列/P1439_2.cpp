/**
 * https://www.luogu.com.cn/problem/P1439
 *
 * @File:   P1439_2.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-15
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    // 使用两行滚动数组
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int curr = i % 2;
        int prev = 1 - curr;
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) {
                dp[curr][j] = dp[prev][j - 1] + 1;
            } else {
                dp[curr][j] = max(dp[prev][j], dp[curr][j - 1]);
            }
        }
    }

    cout << dp[n % 2][n] << endl;

    return 0;
}
