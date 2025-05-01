/**
 * https://www.luogu.com.cn/problem/P3368
 *
 * @File:   P3368.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-23
 *
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // 读取数列长度和操作个数

    vector<int> a(n + 2, 0); // 原数组，多开两个空间防止越界
    vector<int> d(n + 2, 0); // 差分数组

    // 初始化原数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 初始化差分数组
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    // 处理操作
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            // 操作 1：区间 [x, y] 加上 k
            int x, y, k;
            cin >> x >> y >> k;
            d[x] += k;      // 左端点加 k
            if (y + 1 <= n) {
                d[y + 1] -= k; // 右端点的下一个位置减 k
            }
        } else if (op == 2) {
            // 操作 2：查询第 x 个数的值
            int x;
            cin >> x;
            // 计算前缀和
            int result = 0;
            for (int i = 1; i <= x; i++) {
                result += d[i];
            }
            cout << result << endl;
        }
    }

    return 0;
}
