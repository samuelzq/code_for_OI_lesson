/**
 *
 * @File:   P2834.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-07
 *
 */
#include <iostream>
#include <vector>

// 定义模数
const int MOD = 1e9 + 7;

int main() {
    // 优化C++标准库输入输出流，提高效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // 纸币种类数
    int w; // 目标金额

    std::cin >> n >> w;

    std::vector<int> a(n); // 存储纸币面额
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // dp[i] 表示凑出金额 i 的不同纸币组合的数量
    // 大小为 w + 1，因为金额从 0 到 w
    std::vector<int> dp(w + 1, 0);

    // 初始条件：凑出金额 0 有 1 种方式（不支付任何纸币，即空组合）
    dp[0] = 1;

    // 外层循环：遍历每种纸币面额
    // 这种循环顺序（先遍历物品，再遍历容量）确保了每种组合只被计算一次
    for (int j = 0; j < n; ++j) { // 遍历每种纸币 a[j]
        // 内层循环：遍历金额，从当前纸币面额开始
        // 确保使用当前纸币 a[j] 时，是基于不包含 a[j] 的组合，或者 a[j] 是组合中面额最小/次小的纸币
        for (int i = a[j]; i <= w; ++i) { // 遍历金额 i
            // 更新 dp[i]：
            // dp[i] 的当前值（不使用 a[j] 凑出的组合数）
            // 加上 dp[i - a[j]] （使用 a[j] 凑出的组合数）
            // 这里的 dp[i - a[j]] 意味着在凑出 i - a[j] 的组合中，追加了一张 a[j]
            // 由于外层循环保证了 a[j] 是在当前或之前被处理的纸币中面额最大或同大的
            // 因此避免了 (1,2) 和 (2,1) 被重复计数
            dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }
    }

    // 输出最终结果，即凑出金额 w 的纸币组合数量
    std::cout << dp[w] << std::endl;

    return 0;
}
