/**
 *
 * @File:   P1714_2.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-20
 *
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // 读取 n（蛋糕块数）和 m（最多能吃的数量）

    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];  // 读取每块蛋糕的幸运值
    }

    int max_luck = INT_MIN;  // 初始化最大幸运值为最小可能值
    int current_sum = 0;     // 当前窗口的和
    int left = 1;            // 窗口左边界

    for (int right = 1; right <= n; right++) {
        // 将当前元素加入窗口
        current_sum += p[right];

        // 如果窗口大小超过 m，移动左指针缩小窗口
        while (right - left + 1 > m) {
            current_sum -= p[left];
            left++;
        }

        // 更新最大幸运值
        max_luck = max(max_luck, current_sum);
    }

    cout << max_luck << endl;
    return 0;
}
