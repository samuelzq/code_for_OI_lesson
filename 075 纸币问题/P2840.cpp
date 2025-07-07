/**
 * https://www.luogu.com.cn/problem/P2840
 *
 * @File:   P2840.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-03
 *
 */
#include <iostream>
#include <vector>

// 定义模数
const int MOD = 1e9 + 7;

int main() {
    // 优化C++标准库输入输出流，使其与C语言的stdio同步关闭，并解除cin和cout的绑定，提高效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // 纸币种类数
    int w; // 目标金额

    std::cin >> n >> w;

    std::vector<int> a(n); // 存储纸币面额
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // dp[i] 表示凑出金额 i 的不同支付方式的数量
    // 大小为 w + 1，因为金额从 0 到 w
    std::vector<int> dp(w + 1, 0);

    // 初始条件：凑出金额 0 有 1 种方式（不支付任何纸币）
    dp[0] = 1;

    // 外层循环：遍历所有可能的金额，从 1 到 w
    for (int i = 1; i <= w; ++i) {
        // 内层循环：遍历所有纸币面额
        for (int j = 0; j < n; ++j) {
            // 如果当前金额 i 大于或等于纸币面额 a[j]
            // 并且 i - a[j] 这个子问题有解（即 dp[i - a[j]] > 0，或至少不为0）
            // 注意：因为 dp[i - a[j]] 可能是 0 (无法凑出)，但 0 加到 dp[i] 仍然是 0，不影响结果
            if (i >= a[j]) {
                // 更新 dp[i]：
                // dp[i] 的当前值加上所有凑出 (i - a[j]) 的方式数量
                // 因为每种凑出 (i - a[j]) 的方式，都可以通过最后加上一张 a[j] 来形成一种新的凑出 i 的方式。
                // 记得对结果取模
                dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
            }
        }
    }

    // 输出最终结果，即凑出金额 w 的方式数量
    std::cout << dp[w] << std::endl;

    return 0;
}
