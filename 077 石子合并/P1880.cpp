/**
 * https://www.luogu.com.cn/problem/P1880
 *
 * @File:   P1880.cpp
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
    vector<int> stones(2 * n);
    vector<int> prefix(2 * n + 1, 0);

    // 输入并复制数组
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
        stones[i + n] = stones[i];
    }

    // 计算前缀和
    for (int i = 0; i < 2 * n; ++i) {
        prefix[i + 1] = prefix[i] + stones[i];
    }

    // 初始化DP数组
    vector<vector<int>> dp_min(2 * n, vector<int>(2 * n, INT_MAX));
    vector<vector<int>> dp_max(2 * n, vector<int>(2 * n, INT_MIN));

    // 单个石子堆得分为0
    for (int i = 0; i < 2 * n; ++i) {
        dp_min[i][i] = 0;
        dp_max[i][i] = 0;
    }

    // 区间DP
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= 2 * n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                int sum = prefix[j + 1] - prefix[i];
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + sum);
                dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + sum);
            }
        }
    }

    // 寻找最优解
    int min_score = INT_MAX, max_score = INT_MIN;
    for (int i = 0; i < n; ++i) {
        min_score = min(min_score, dp_min[i][i + n - 1]);
        max_score = max(max_score, dp_max[i][i + n - 1]);
    }

    cout << min_score << endl << max_score << endl;

    return 0;
}
