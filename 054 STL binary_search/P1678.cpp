/**
 * https://www.luogu.com.cn/problem/P1678
 *
 * @File:   P1678.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <bits/stdc++.h>

using namespace std;

int a[100005];
int n, m;

int main(void) {
    unsigned long long sum = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 使用 STL 排序
    sort(a, a + n);

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        // 用 lower_bound 寻找第一个 >= b 的位置
        auto it = lower_bound(a, a + n, b);

        if (it == a) {
            // 如果 b 小于数组最小值
            sum += a[0] - b;
        } else if (it == a + n) {
            // 如果 b 大于数组最大值
            sum += b - a[n - 1];
        } else {
            // 在数组范围内，比较前一个元素和当前位置的距离
            int d1 = b - *(it - 1); // 前一个元素的距离
            int d2 = *it - b;       // 当前元素的距离
            sum += min(d1, d2);
        }
    }

    cout << sum << endl;
    return 0;
}

