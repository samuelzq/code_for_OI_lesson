/**
 *
 * @File:   P2659_2.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-31
 *
 **/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // 用于 std::max 函数

int main() {
    // 提高 C++ 标准流的输入/输出性能
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 使用 long long 类型存储序列元素，以避免在计算乘积时发生溢出
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Li[i] 存储的是元素 a[i] 左侧第一个严格小于 a[i] 的元素的索引。
    // 如果不存在这样的元素，则 Li[i] 为 -1（表示在索引 0 之前的虚拟边界）。
    std::vector<int> Li(n);
    std::stack<int> s_left; // 栈用于存储索引

    for (int i = 0; i < n; ++i) {
        // 从栈中弹出所有大于或等于当前元素 a[i] 的元素。
        // 因为它们不可能是 a[i] 或后续元素的左侧最近更小元素。
        while (!s_left.empty() && a[s_left.top()] >= a[i]) {
            s_left.pop();
        }
        // 如果栈为空，则表示 a[i] 左侧没有比它更小的元素。
        // 所以，左边界设为 -1（即数组的起始之前）。
        if (s_left.empty()) {
            Li[i] = -1;
        } else {
            // 栈顶元素就是左侧第一个比 a[i] 小的元素的索引。
            Li[i] = s_left.top();
        }
        // 将当前元素的索引压入栈中。
        s_left.push(i);
    }

    // Ri[i] 存储的是元素 a[i] 右侧第一个严格小于 a[i] 的元素的索引。
    // 如果不存在这样的元素，则 Ri[i] 为 n（表示在索引 n-1 之后的虚拟边界）。
    std::vector<int> Ri(n);
    std::stack<int> s_right; // 栈用于存储索引

    // 从右到左遍历序列
    for (int i = n - 1; i >= 0; --i) {
        // 从栈中弹出所有大于或等于当前元素 a[i] 的元素。
        while (!s_right.empty() && a[s_right.top()] >= a[i]) {
            s_right.pop();
        }
        // 如果栈为空，则表示 a[i] 右侧没有比它更小的元素。
        // 所以，右边界设为 n（即数组的末尾之后）。
        if (s_right.empty()) {
            Ri[i] = n;
        } else {
            // 栈顶元素就是右侧第一个比 a[i] 小的元素的索引。
            Ri[i] = s_right.top();
        }
        // 将当前元素的索引压入栈中。
        s_right.push(i);
    }

    // 初始化最大美丽系数为 0
    long long max_beauty_coefficient = 0;

    // 遍历每个元素 a[i]，计算它作为区间最小值时的美丽度
    for (int i = 0; i < n; ++i) {
        // 以 a[i] 为最小值的最宽子数组的有效左边界是 Li[i] + 1 (因为 Li[i] 是排他的)
        // 有效右边界是 Ri[i] - 1 (因为 Ri[i] 是排他的)
        // 因此，a[i] 作为最小值的最宽子数组的长度是 (Ri[i] - 1) - (Li[i] + 1) + 1
        // 简化后为 Ri[i] - Li[i] - 1
        long long current_length = (long long)Ri[i] - Li[i] - 1;
        // 计算当前区间的美丽度：长度乘以最小值 a[i]
        long long current_beauty = current_length * a[i];

        // 更新迄今为止找到的最大美丽系数
        max_beauty_coefficient = std::max(max_beauty_coefficient, current_beauty);
    }

    // 输出最终的最大美丽系数
    std::cout << max_beauty_coefficient << std::endl;

    return 0;
}
