/**
 * https://www.luogu.com.cn/problem/P1614
 *
 * @File:   P1614.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-15
 *
 */
#include <iostream>
#include <vector>
#include <climits> // 用于INT_MAX
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 读取刺痛值
    vector<int> a(n + 1, 0); // 从1开始存储
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 计算前缀和
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // 找到连续m个刺痛值的最小和
    int min_sum = INT_MAX; // 初始化为最大值
    for (int i = 1; i <= n - m + 1; ++i) {
        int current_sum = prefix[i + m - 1] - prefix[i - 1];
        if (current_sum < min_sum) {
            min_sum = current_sum;
        }
    }

    // 输出结果
    cout << min_sum << endl;

    return 0;
}
