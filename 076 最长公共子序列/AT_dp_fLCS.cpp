/**
 * https://www.luogu.com.cn/problem/AT_dp_f
 *
 * @File:   AT_dp_fLCS.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-12
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string findLCS(const string& s, const string& t) {
    int m = s.length();
    int n = t.length();

    // 创建DP表，dp[i][j]表示s前i个字符和t前j个字符的LCS长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 填充DP表
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 回溯构造LCS字符串
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs.push_back(s[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s, t;
    cin >> s >> t;  // 读取两个字符串

    string result = findLCS(s, t);
    cout << result << endl;

    return 0;
}
