/**
 * https://www.luogu.com.cn/problem/P1714
 *
 * @File:   P1714.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-19
 *
 */
#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // 读取 n（蛋糕块数）和 m（最多能吃的数量）

    vector<int> p(n + 1, 0);  // 存储蛋糕幸运值，索引从 1 开始
    vector<int> prefix(n + 1, 0);  // 前缀和数组

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix[i] = prefix[i - 1] + p[i];  // 计算前缀和
    }

    int max_luck = INT_MIN;  // 记录最大幸运值
    deque<int> q;  // 单调队列，存储可能的最小前缀和的下标

    for (int r = 1; r <= n; r++) {
        // 维护队列单调性
        while (!q.empty() && prefix[q.back()] > prefix[r - 1]) {
            q.pop_back();
        }
        q.push_back(r - 1);  // 将当前左端点加入队列

        // 移除超出窗口范围的左端点
        while (!q.empty() && r - q.front() > m) {
            q.pop_front();
        }

        // 更新答案
        if (!q.empty()) {
            max_luck = max(max_luck, prefix[r] - prefix[q.front()]);
        }
    }
    cout << max_luck << endl;  // 输出最大幸运值
    return 0;
}

