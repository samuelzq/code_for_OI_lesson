/**
 * https://www.luogu.com.cn/problem/B3637
 *
 * @File:   B3637.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-08
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // dp[i] 表示以 nums[i] 结尾的最长上升子序列的长度
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 找出 dp 数组中的最大值
    int max_len = *max_element(dp.begin(), dp.end());
    cout << max_len << endl;

    return 0;
}
