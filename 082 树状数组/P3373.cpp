/**
 * https://www.luogu.com.cn/problem/P3373
 *
 * @File:   P3373.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-28
 *
 **/
#include <iostream>
#include <vector>

const int MAX_N = 100005;
// 定义全局变量，模拟C风格
long long N_SIZE; // 数列数字的个数
long long MOD;    // 模数

// 结构体表示线段树的节点
// sum: 当前区间和
// mul_lazy: 乘法懒惰标记
// add_lazy: 加法懒惰标记
struct Node {
    unsigned long long sum;
    unsigned long long mul_lazy;
    unsigned long long add_lazy;
};

// 线段树数组（大小通常为 4 * N）
Node tree[4 * MAX_N];
unsigned long long initial_array[MAX_N]; // 存储初始数列

// --- 辅助函数 ---

// 向上更新节点信息（从子节点计算父节点）
void push_up(long long node_idx) {
    tree[node_idx].sum = (tree[node_idx * 2].sum + tree[node_idx * 2 + 1].sum) % MOD;
}

// 向下传递懒惰标记
// node_idx: 当前节点索引
// left_len: 左子节点区间的长度
// right_len: 右子节点区间的长度
void push_down(long long node_idx, long long left_len, long long right_len) {
    long long mul = tree[node_idx].mul_lazy;
    long long add = tree[node_idx].add_lazy;

    if (mul == 1 && add == 0) { // 没有懒惰标记，直接返回
        return;
    }

    // 更新左子节点
    tree[node_idx * 2].sum = (tree[node_idx * 2].sum * mul % MOD + add * left_len % MOD) % MOD;
    tree[node_idx * 2].mul_lazy = (tree[node_idx * 2].mul_lazy * mul) % MOD;
    tree[node_idx * 2].add_lazy = (tree[node_idx * 2].add_lazy * mul % MOD + add) % MOD;

    // 更新右子节点
    tree[node_idx * 2 + 1].sum = (tree[node_idx * 2 + 1].sum * mul % MOD + add * right_len % MOD) % MOD;
    tree[node_idx * 2 + 1].mul_lazy = (tree[node_idx * 2 + 1].mul_lazy * mul) % MOD;
    tree[node_idx * 2 + 1].add_lazy = (tree[node_idx * 2 + 1].add_lazy * mul % MOD + add) % MOD;

    // 清除当前节点的懒惰标记
    tree[node_idx].mul_lazy = 1;
    tree[node_idx].add_lazy = 0;
}

// --- 线段树操作 ---

// 构建线段树
// node_idx: 当前节点索引
// L: 当前区间左边界
// R: 当前区间右边界
void build(long long node_idx, long long L, long long R) {
    tree[node_idx].mul_lazy = 1; // 乘法懒惰标记初始为1
    tree[node_idx].add_lazy = 0; // 加法懒惰标记初始为0

    if (L == R) { // 叶子节点
        tree[node_idx].sum = initial_array[L] % MOD;
        return;
    }

    long long mid = (L + R) / 2;
    build(node_idx * 2, L, mid);         // 构建左子树
    build(node_idx * 2 + 1, mid + 1, R); // 构建右子树
    push_up(node_idx);                   // 更新当前节点信息
}

// 区间乘法操作
// node_idx: 当前节点索引
// L, R: 当前节点表示的区间范围
// query_L, query_R: 要修改的区间范围
// k: 乘数
void update_multiply(long long node_idx, long long L, long long R, long long query_L, long long query_R, long long k) {
    if (query_L <= L && R <= query_R) { // 当前区间完全被查询区间覆盖
        tree[node_idx].sum = (tree[node_idx].sum * k) % MOD;
        tree[node_idx].mul_lazy = (tree[node_idx].mul_lazy * k) % MOD;
        tree[node_idx].add_lazy = (tree[node_idx].add_lazy * k) % MOD;
        return;
    }

    long long mid = (L + R) / 2;
    push_down(node_idx, mid - L + 1, R - mid); // 向下传递懒惰标记

    if (query_L <= mid) { // 查询区间与左子区间有交集
        update_multiply(node_idx * 2, L, mid, query_L, query_R, k);
    }
    if (query_R > mid) { // 查询区间与右子区间有交集
        update_multiply(node_idx * 2 + 1, mid + 1, R, query_L, query_R, k);
    }
    push_up(node_idx); // 更新当前节点信息
}

// 区间加法操作
// node_idx: 当前节点索引
// L, R: 当前节点表示的区间范围
// query_L, query_R: 要修改的区间范围
// k: 加数
void update_add(long long node_idx, long long L, long long R, long long query_L, long long query_R, long long k) {
    if (query_L <= L && R <= query_R) { // 当前区间完全被查询区间覆盖
        tree[node_idx].sum = (tree[node_idx].sum + k * (R - L + 1)) % MOD;
        tree[node_idx].add_lazy = (tree[node_idx].add_lazy + k) % MOD;
        return;
    }

    long long mid = (L + R) / 2;
    push_down(node_idx, mid - L + 1, R - mid); // 向下传递懒惰标记

    if (query_L <= mid) { // 查询区间与左子区间有交集
        update_add(node_idx * 2, L, mid, query_L, query_R, k);
    }
    if (query_R > mid) { // 查询区间与右子区间有交集
        update_add(node_idx * 2 + 1, mid + 1, R, query_L, query_R, k);
    }
    push_up(node_idx); // 更新当前节点信息
}

// 区间求和操作
// node_idx: 当前节点索引
// L, R: 当前节点表示的区间范围
// query_L, query_R: 要查询的区间范围
long long query_sum(long long node_idx, long long L, long long R, long long query_L, long long query_R) {
    if (query_L <= L && R <= query_R) { // 当前区间完全被查询区间覆盖
        return tree[node_idx].sum;
    }

    long long mid = (L + R) / 2;
    push_down(node_idx, mid - L + 1, R - mid); // 向下传递懒惰标记

    long long res = 0;
    if (query_L <= mid) { // 查询区间与左子区间有交集
        res = (res + query_sum(node_idx * 2, L, mid, query_L, query_R)) % MOD;
    }
    if (query_R > mid) { // 查询区间与右子区间有交集
        res = (res + query_sum(node_idx * 2 + 1, mid + 1, R, query_L, query_R)) % MOD;
    }
    return res;
}

// --- 主函数 ---

int main() {
    // 优化C++标准输入/输出流
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long q_ops; // 操作的总个数

    std::cin >> N_SIZE >> q_ops >> MOD;

    for (long long i = 1; i <= N_SIZE; ++i) {
        std::cin >> initial_array[i];
    }

    build(1, 1, N_SIZE); // 构建线段树

    for (long long i = 0; i < q_ops; ++i) {
        long long type;
        std::cin >> type;
        if (type == 1) { // 操作 1: 区间乘法
            unsigned long long x, y, k;
            std::cin >> x >> y >> k;
            update_multiply(1, 1, N_SIZE, x, y, k);
        } else if (type == 2) { // 操作 2: 区间加法
            unsigned long long x, y, k;
            std::cin >> x >> y >> k;
            update_add(1, 1, N_SIZE, x, y, k);
        } else { // 操作 3: 区间求和
            unsigned long long x, y;
            std::cin >> x >> y;
            std::cout << query_sum(1, 1, N_SIZE, x, y) << "\n";
        }
    }

    return 0;
}
