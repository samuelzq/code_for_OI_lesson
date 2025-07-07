/**
 * https://www.luogu.com.cn/problem/P2842
 *
 * @File:   P2842.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-03
 *
 */
#include <iostream>
#include <vector>
#include <algorithm> // for std::min

const int INF = 1e9; // 定义一个足够大的值表示无穷大

int main() {
    int n; // 纸币种类数
    int w; // 目标金额

    std::cin >> n >> w;

    std::vector<int> a(n); // 存储纸币面额
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // dp[i] 表示凑出金额 i 所需的最少纸币张数
    // 初始化为 INF，dp[0] 初始化为 0
    std::vector<int> dp(w + 1, INF);
    dp[0] = 0;

    // 遍历所有可能的金额，从 1 到 w
    for (int i = 1; i <= w; ++i) {
        // 遍历所有纸币面额
        for (int j = 0; j < n; ++j) {
            // 如果当前金额 i 大于或等于纸币面额 a[j]
            // 并且 dp[i - a[j]] 不是 INF (表示 i - a[j] 可以被凑出)
            if (i >= a[j] && dp[i - a[j]] != INF) {
                // 更新 dp[i]，取最小值
                // dp[i - a[j]] + 1 意味着用一张面额为 a[j] 的纸币来凑 i
                dp[i] = std::min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    // 输出结果
    if (dp[w] == INF) {
        // 如果 dp[w] 仍然是 INF，表示无法凑出金额 w
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[w] << std::endl;
    }

    return 0;
}
