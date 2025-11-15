/**
 * https://www.luogu.com.cn/problem/P5854
 *
 * @File:   P5854.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-31
 *
 **/
#include <iostream>
#include <vector>
#include <stack>
#include <numeric> // 用于一些标准库函数，本例中非必需但常见

int main() {
    // 优化 C++ 标准输入输出流，提高程序运行速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // 序列的长度 n
    std::cin >> n;

    // p_val[i] 存储节点索引 i 对应的权值 p_i
    // 使用 1-based 索引以便与题目约定（节点下标从 1 开始）保持一致
    // p_val[0] 将不会被使用
    std::vector<int> p_val(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p_val[i];
    }

    // left_child[i] 存储节点 i 的左儿子的编号（如果不存在则为 0）
    // right_child[i] 存储节点 i 的右儿子的编号（如果不存在则为 0）
    std::vector<int> left_child(n + 1, 0);
    std::vector<int> right_child(n + 1, 0);

    // 单调栈用于构建笛卡尔树
    // 栈中存储的是节点的索引（1 到 n）
    // 栈中的元素 p_val[stack.top()] 始终保持递增顺序（即栈顶元素的值最小）
    std::stack<int> s;

    // 从左到右遍历序列中的每个元素（节点索引从 1 到 n）
    for (int i = 1; i <= n; ++i) {
        // 'last_popped' 将指向那些被弹出栈的、且值大于当前节点 p_val[i] 的节点。
        // 这个 'last_popped' 最终会成为当前节点 i 的左子节点。
        int last_popped = 0; 

        // 当栈不为空，并且栈顶节点的值 p_val[s.top()] 大于当前节点的值 p_val[i] 时，
        // 说明栈顶节点不可能是当前节点 i 的祖先（不满足小根堆性质）。
        // 因此，栈顶节点需要被弹出。
        while (!s.empty() && p_val[s.top()] > p_val[i]) {
            last_popped = s.top(); // 记录当前弹出的节点
            s.pop(); // 弹出栈顶
        }

        // 循环结束后，如果 'last_popped' 不为 0，
        // 说明我们找到了一个或多个比当前节点 p_val[i] 大的元素被弹出。
        // 最后一个被弹出的元素 (last_popped) 成为当前节点 i 的**左子节点**。
        // 这符合笛卡尔树的两个性质：
        // 1. BST 性质：last_popped 的索引小于 i。
        // 2. 小根堆性质：p_val[i] 小于 p_val[last_popped]。
        if (last_popped != 0) {
            left_child[i] = last_popped;
        }

        // 如果栈不为空，则栈顶元素 p_val[s.top()] 必然小于 p_val[i]。
        // 此时，s.top() 成为当前节点 i 的**父节点**。
        // 由于 i 的索引大于 s.top() 的索引（i 在 s.top() 的右边），
        // i 成为 s.top() 的**右子节点**。
        if (!s.empty()) {
            right_child[s.top()] = i;
        }

        // 将当前节点 i 的索引压入栈中，以备后续节点的处理。
        // 压入后，栈将继续保持 p_val 递增的单调性。
        s.push(i);
    }

    // 计算题目要求的两个异或和
    long long xor_sum_left = 0;
    long long xor_sum_right = 0;

    for (int i = 1; i <= n; ++i) {
        // 计算 i * (left_child[i] + 1) 并累加到 xor_sum_left
        xor_sum_left ^= (static_cast<long long>(i) * (left_child[i] + 1));
        // 计算 i * (right_child[i] + 1) 并累加到 xor_sum_right
        xor_sum_right ^= (static_cast<long long>(i) * (right_child[i] + 1));
    }

    // 输出最终结果
    std::cout << xor_sum_left << " " << xor_sum_right << "\n";

    return 0;
}

