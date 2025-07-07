/**
 * https://www.luogu.com.cn/problem/P1439
 *
 * @File:   P1439.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-12
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p1(n), p2(n);
    // 读取两个排列
    for (int i = 0; i < n; i++) cin >> p1[i];
    for (int i = 0; i < n; i++) cin >> p2[i];

    // 建立p1中元素到位置的映射
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p1[i - 1] == p2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][n] << endl;
    return 0;
}
