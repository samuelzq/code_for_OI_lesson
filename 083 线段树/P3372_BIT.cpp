/**
 * https://www.luogu.com.cn/problem/P3372
 *
 * @File:   P3372_bit.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-28
 *
 **/
#include <iostream>

const int N_MAX = 100005; // 根据题目 N 的范围调整

// bit_d 用于存储差分数组 D[i] 的累积和
unsigned long long bit_d[N_MAX];

// bit_id 用于存储 i * D[i] 的累积和
unsigned long long bit_id[N_MAX];

int fenwick_tree_n; // 数列的长度 N

// --- 辅助函数：单个树状数组的点更新 ---
// 功能：在指定索引处增加/减少一个值
// 参数：
//   bit_arr: 要操作的树状数组（全局变量）
//   index: 1-based 索引（从1开始计数）
//   delta: 要增加或减少的值（可以使用 long long 来处理负数，内部处理类型转换）
void point_update(unsigned long long* bit_arr, int index, unsigned long long delta) {
    while (index <= fenwick_tree_n) {
        // 由于 delta 可以是负数，而 bit_arr 是 unsigned long long，
        // C++ 会将负数 delta 转换为无符号类型，然后执行操作。
        // 这在数学上等价于减法，但需要确保最终结果不会小于0（即不会发生无符号数下溢）。
        // 题目要求使用 unsigned long long 且提到结果可能很大，
        // 隐式假定最终或中间状态的求和结果不会为负。
        bit_arr[index] += delta;
        index += index & (-index); // 移动到下一个需要更新的父节点
    }
}

// --- 辅助函数：单个树状数组的前缀和查询 ---
// 功能：查询从1到指定索引的累积和
// 参数：
//   bit_arr: 要查询的树状数组（全局变量）
//   index: 1-based 索引
// 返回值：累积和
unsigned long long query(unsigned long long* bit_arr, int index) {
    unsigned long long sum = 0;
    while (index > 0) {
        sum += bit_arr[index];
        index -= index & (-index); // 移动到上一个需要累加的节点
    }
    return sum;
}


// --- 操作1：区间修改 ---
// 功能：将区间 [x, y] 内的每个数加上 k
// 参数：
//   x, y: 区间的起始和结束索引（1-based）
//   k: 要增加的值
void range_update(int x, int y, long long k) {
    // 对差分数组 D 的点修改：D[x] += k, D[y+1] -= k
    point_update(bit_d, x, k);
    if (y + 1 <= fenwick_tree_n) {
        point_update(bit_d, y + 1, -k);
    }

    // 对 i * D[i] 的点修改：在 x 处增加 x*k，在 y+1 处减少 (y+1)*k
    point_update(bit_id, x, (unsigned long long)x * k);
    if (y + 1 <= fenwick_tree_n) {
        point_update(bit_id, y + 1, (unsigned long long)(y + 1) * (-k));
    }
}

// --- 辅助函数：查询前 p 个数的总和 ---
// 功能：计算数列 A 中从 A[1] 到 A[p] 的累积和
// 参数：
//   p: 结束索引（1-based）
// 返回值：累积和
unsigned long long prefix_sum(int p) {
    if (p <= 0) return 0; // 如果索引无效或小于等于0，返回0

    // 根据公式：SumA(p) = (p + 1) * sum_{j=1 to p} D[j] - sum_{j=1 to p} (j * D[j])
    unsigned long long sum_d = query(bit_d, p);
    unsigned long long sum_id = query(bit_id, p);

    // 在 unsigned long long 上执行减法时，需要保证被减数大于等于减数，
    // 否则会发生无符号数下溢。根据问题类型，通常会保证结果为非负。
    return (unsigned long long)(p + 1) * sum_d - sum_id;
}

// --- 操作2：区间求和 ---
// 功能：求出区间 [x, y] 内所有数的和
// 参数：
//   x, y: 区间的起始和结束索引（1-based）
// 返回值：区间内的总和
unsigned long long range_query(int x, int y) {
    // 区间和 = 前 y 个数的和 - 前 (x-1) 个数的和
    return prefix_sum(y) - prefix_sum(x - 1);
}

int main() {
    // 优化C++标准输入/输出流，提高效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m; // n: 数列数字的个数, m: 操作的总个数
    std::cin >> n >> m;
    fenwick_tree_n = n;

    // 处理初始数列的 n 个数字
    // 每个初始值 a_i 可以看作是对区间 [i, i] 进行了值 a_i 的增加操作
    for (int i = 1; i <= n; ++i) {
        unsigned long long val;
        std::cin >> val;
        range_update(i, i, val); // 对每个位置进行点修改
    }

    // 处理接下来的 m 个操作
    for (int op_count = 0; op_count < m; ++op_count) {
        int type; // 操作类型
        std::cin >> type;
        if (type == 1) { // 类型1: 区间修改
            unsigned long long x, y;
            unsigned long long k;
            std::cin >> x >> y >> k;
            range_update(x, y, k);
        } else { // 类型2: 区间求和
            int x, y;
            std::cin >> x >> y;
            std::cout << range_query(x, y) << "\n"; // 输出结果
        }
    }

    return 0;
}
