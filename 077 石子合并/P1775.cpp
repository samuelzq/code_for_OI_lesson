/**
 * https://www.luogu.com.cn/problem/P1775
 *
 * @File:   P1775.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-21
 *
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    vector<int> prefix(n + 1, 0); // 前缀和数组

    // 输入石子质量并计算前缀和
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
        prefix[i + 1] = prefix[i] + stones[i];
    }

    // DP数组初始化
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 区间DP
    for (int len = 2; len <= n; ++len) {        // 枚举区间长度
        for (int i = 0; i + len <= n; ++i) {    // 枚举区间起点
            int j = i + len - 1;                // 区间终点
            dp[i][j] = INT_MAX;                 // 初始化为最大值

            // 枚举分割点k
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + prefix[j + 1] - prefix[i];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    // 输出合并1~n堆的最小代价
    cout << dp[0][n - 1] << endl;

    return 0;
}
