/**
 * https://www.luogu.com.cn/problem/P1678
 *
 * @File:   P1678_for_each.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    unsigned long long sum = 0;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // 排序数组 a
    sort(a.begin(), a.end());

    // 使用 lambda 表达式查找并累加
    auto accumulate_difference = [&a, &sum](int b_value) {
        auto it = lower_bound(a.begin(), a.end(), b_value);

        if (it == a.begin()) {
            // 如果 b_value 小于数组最小值
            sum += *a.begin() - b_value;
        } else if (it == a.end()) {
            // 如果 b_value 大于数组最大值
            sum += b_value - *(a.end() - 1);
        } else {
            // 计算与当前值和前一个值的最小距离
            int d1 = b_value - *(it - 1); // 距离前一个值
            int d2 = *it - b_value;       // 距离当前值
            sum += min(d1, d2);
        }
    };

    // 遍历 b 的所有值，调用 lambda 表达式处理
    for_each(b.begin(), b.end(), accumulate_difference);

    // 输出结果
    cout << sum << endl;
    return 0;
}
