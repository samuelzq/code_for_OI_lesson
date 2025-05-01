/**
 * https://www.luogu.com.cn/problem/P2367
 *
 * @File:   P2367.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-23
 *
 */
#include <iostream>
#include <vector>
#include <climits> // 包含INT_MAX

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<long long> a(n + 1, 0); // 原始数组
    vector<long long> d(n + 2, 0); // 差分数组
    vector<long long> prefix_sum(n + 1, 0); // 前缀和数组

    // 初始化原始数组和差分数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }

    // 处理增加分数的操作
    while (p--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    // 计算前缀和，即最终的成绩
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + d[i];
    }

    // 找到最低分
    long long min_score = LLONG_MAX; // 初始化为最大值
    for (int i = 1; i <= n; i++) {
        min_score = min(min_score, prefix_sum[i]);
    }

    cout << min_score << endl;

    return 0;
}
