/**
 *
 * @File:   B4273.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-31
 *
 **/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For std::max
#include <utility>   // For std::pair

// 全局变量用于存储树结构和数据，方便DFS访问
std::vector<int> heights; // 存储每列的高度
std::vector<int> left_child; // 存储左子节点索引
std::vector<int> right_child; // 存储右子节点索引
long long max_area = 0; // 全局最大面积

// DFS 函数：计算以 node_idx 为根的子树所覆盖的原始区间的 [最左索引, 最右索引]
// 同时计算并更新以当前节点高度为高的最大矩形面积
std::pair<int, int> dfs_calculate_area(int node_idx) {
    // 基本情况：如果节点不存在，返回无效区间（例如，左边界比右边界大）
    if (node_idx == 0) {
        return {2000000, 0}; // 一个足够大作为左边界，0作为右边界，使其区间无效 (left > right)
    }

    // 递归处理左子树
    std::pair<int, int> left_range = dfs_calculate_area(left_child[node_idx]);
    // 递归处理右子树
    std::pair<int, int> right_range = dfs_calculate_area(right_child[node_idx]);

    // 计算当前子树的最左索引和最右索引
    // 当前节点可能只有一个子节点或者没有子节点
    int current_left_idx = (left_range.first == 2000000) ? node_idx : left_range.first;
    int current_right_idx = (right_range.second == 0) ? node_idx : right_range.second;

    // 计算以当前节点高度为高的矩形面积
    // 宽度 = 最右索引 - 最左索引 + 1
    long long current_width = static_cast<long long>(current_right_idx) - current_left_idx + 1;
    long long current_height = heights[node_idx];
    max_area = std::max(max_area, current_width * current_height);

    // 返回当前子树所覆盖的 [最左索引, 最右索引]
    return {current_left_idx, current_right_idx};
}


int main() {
    // 优化 C++ 标准输入输出流，提高程序运行速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // 纸片完整边的长度，即直方图的列数
    std::cin >> n;

    // heights 存储每列格子残存部分的高度。
    // 使用 1-based 索引。
    heights.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> heights[i];
    }

    // left_child[i] 存储节点 i 的左儿子的编号（如果不存在则为 0）
    // right_child[i] 存储节点 i 的右儿子的编号（如果不存在则为 0）
    left_child.resize(n + 1, 0);
    right_child.resize(n + 1, 0);

    // Monotonic stack to build the Cartesian Tree
    // 栈中存储的是节点的索引（1 到 n）
    // 栈中的元素 heights[stack.top()] 始终保持递增顺序（即栈顶元素的值最小）
    std::stack<int> s;
    int root_node_idx = 0; // 记录笛卡尔树的根节点

    // 从左到右遍历序列中的每个元素（节点索引从 1 到 n）
    for (int i = 1; i <= n; ++i) {
        int last_popped_child = 0; // 记录当前弹出的节点中，最后一个被弹出的那个

        // 当栈不为空，并且栈顶节点的值 heights[s.top()] 大于当前节点的值 heights[i] 时，
        // 说明栈顶节点不可能成为当前节点 i 的祖先（不满足小根堆性质）。
        // 因此，栈顶节点需要被弹出。
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            last_popped_child = s.top(); // 记录当前弹出的节点
            s.pop(); // 弹出栈顶
        }

        // 循环结束后，如果 'last_popped_child' 不为 0，
        // 说明我们找到了一个或多个比当前节点 heights[i] 大的元素被弹出。
        // 最后一个被弹出的元素 (last_popped_child) 成为当前节点 i 的**左子节点**。
        // 这符合笛卡尔树的两个性质：
        // 1. BST 性质：last_popped_child 的索引小于 i。
        // 2. 小根堆性质：heights[i] 小于 heights[last_popped_child]。
        if (last_popped_child != 0) {
            left_child[i] = last_popped_child;
        }

        // 如果栈不为空，则栈顶元素 heights[s.top()] 必然小于 heights[i]。
        // 此时，s.top() 成为当前节点 i 的**父节点**。
        // 由于 i 的索引大于 s.top() 的索引（i 在 s.top() 的右边），
        // i 成为 s.top() 的**右子节点**。
        if (!s.empty()) {
            right_child[s.top()] = i;
        } else {
            // 如果栈为空，说明当前节点 i 是目前为止处理过的所有元素中最小的，
            // 那么它就是笛卡尔树的根节点。
            root_node_idx = i;
        }

        // 将当前节点 i 的索引压入栈中，以备后续节点的处理。
        // 压入后，栈将继续保持 heights 递增的单调性。
        s.push(i);
    }

    // 如果循环结束后 root_node_idx 仍为0 (N=0或N=1且未被更新), 栈顶元素就是根节点
    // 当然，在 for 循环的 else 块中已经处理了 root_node_idx 的确定
    // 如果循环结束栈中还有元素，栈底元素是根节点。
    // 最简单的确定根节点方法是：在所有节点的父节点确定后，
    // 遍历哪个节点没有父节点，它就是根节点。但我们已经用 else if(!s.empty())
    // 确定了每次插入时，新插入节点 i 的父节点，
    // 只有当 stack 为空时，i 是新root。
    // For a permutation from 1 to N, there will always be a root.

    // 从笛卡尔树的根节点开始 DFS 计算最大面积
    dfs_calculate_area(root_node_idx);

    // 输出最大面积
    std::cout << max_area << "\n";

    return 0;
}
