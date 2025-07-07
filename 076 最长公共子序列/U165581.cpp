/**
 * https://www.luogu.com.cn/problem/U165581
 *
 * @File:   U165581.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-12
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string X, Y;
    int m, n;
    cin >> X >> Y;  // 读取两个字符串

    m = X.length();
    n = Y.length();

    // 创建DP表，dp[i][j]表示X前i个字符和Y前j个字符的LCS长度
    int dp[m + 1][n + 1];

    // 初始化边界条件
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;  // Y为空字符串时
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;  // X为空字符串时
    }

    // 填充DP表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                // 当前字符匹配，长度+1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 当前字符不匹配，取上方或左方的最大值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 输出结果
    cout << dp[m][n] << endl;

    return 0;
}
