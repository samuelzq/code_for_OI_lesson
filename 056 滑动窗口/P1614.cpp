/**
 * https://www.luogu.com.cn/problem/P1614
 *
 * @File:   P1614.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-19
 *
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // 读取 n 和 m

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // 读取 n 个刺痛值
    }

    // 计算第一个窗口的和
    int current_sum = 0;
    for (int i = 0; i < m; i++) {
        current_sum += arr[i];
    }

    int min_sum = current_sum;

    // 滑动窗口遍历
    for (int i = m; i < n; i++) {
        current_sum = current_sum - arr[i - m] + arr[i]; // 移动窗口
        min_sum = min(min_sum, current_sum); // 记录最小值
    }

    cout << min_sum << endl; // 输出结果
    return 0;
}

