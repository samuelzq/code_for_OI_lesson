/**
 * https://www.luogu.com.cn/problem/P1435
 *
 * @File:   P1435.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-21
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // dp[i][j]表示将s[i..j]变成回文的最少插入次数
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 区间DP，按长度从小到大计算
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1];
            } else {
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}
