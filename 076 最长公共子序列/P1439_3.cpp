/**
 * https://www.luogu.com.cn/problem/P1439
 *
 * @File:   P1439_3.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-15
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> dp(n + 1, 0);
    int prev_diag = 0;  // 保存左上角的值

    for (int i = 1; i <= n; ++i) {
        prev_diag = 0;  // 每行开始时重置
        for (int j = 1; j <= n; ++j) {
            int temp = dp[j];  // 保存当前i（上边的值），下一轮会成为prev_diag
            if (a[i] == b[j]) {
                dp[j] = prev_diag + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev_diag = temp;  // 更新为左上角的值
        }
    }

    cout << dp[n] << endl;

    return 0;
}
