/**
 * https://www.luogu.com.cn/problem/P3372
 *
 * @File:   P3372.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-28
 *
 **/
#include <iostream>
#include <vector>

#define ULL unsigned long long
const int N_MAX = 100005; // 根据题目 N 的范围调整
ULL a[N_MAX];      // 原始数组

struct Node {
    ULL sum;
    ULL lazy; // 懒惰标记，表示区间内每个元素需要加上的值
};

Node tree[4 * N_MAX]; // 线段树数组，通常需要 4 倍空间

// 向上更新父节点信息
void pushup(int p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

// 向下传递懒惰标记
// p: 当前节点索引
// l, r: 当前节点代表的区间 [l, r]
void pushdown(int p, int l, int r) {
    if (tree[p].lazy == 0) { // 如果没有懒惰标记，直接返回
        return;
    }

    int mid = l + ((r - l) >> 1);

    // 更新左子节点
    // 左子节点的和增加：懒惰标记 * 左子节点区间长度
    tree[p << 1].sum += tree[p].lazy * (mid - l + 1);
    // 左子节点的懒惰标记增加：父节点的懒惰标记
    tree[p << 1].lazy += tree[p].lazy;

    // 更新右子节点
    // 右子节点的和增加：懒惰标记 * 右子节点区间长度
    tree[p << 1 | 1].sum += tree[p].lazy * (r - (mid + 1) + 1);
    // 右子节点的懒惰标记增加：父节点的懒惰标记
    tree[p << 1 | 1].lazy += tree[p].lazy;

    // 清除当前节点的懒惰标记
    tree[p].lazy = 0;
}

// 构建线段树
// p: 当前节点索引
// l, r: 当前节点代表的区间 [l, r]
void build(int p, int l, int r) {
    tree[p].lazy = 0; // 初始化懒惰标记

    if (l == r) { // 叶子节点，直接赋值
        tree[p].sum = a[l];
        return;
    }

    int mid = l + ((r - l) >> 1); // 计算中间点
    build(p << 1, l, mid);         // 递归构建左子树
    build(p << 1 | 1, mid + 1, r); // 递归构建右子树
    pushup(p);                     // 向上合并子节点信息
}

// 区间更新操作
// p: 当前节点索引
// l, r: 当前节点代表的区间 [l, r]
// ql, qr: 查询/更新的目标区间 [ql, qr]
// k: 要加上的值
void update(int p, int l, int r, int ql, int qr, ULL k) {
    // 如果当前节点区间完全包含在目标区间内
    if (ql <= l && r <= qr) {
        tree[p].sum += (long long)k * (r - l + 1); // 更新当前节点的和
        tree[p].lazy += k;                         // 更新当前节点的懒惰标记
        return;
    }

    pushdown(p, l, r); // 下推懒惰标记

    int mid = l + ((r - l) >> 1);
    // 如果目标区间与左子树有交集，则递归更新左子树
    if (ql <= mid) {
        update(p << 1, l, mid, ql, qr, k);
    }
    // 如果目标区间与右子树有交集，则递归更新右子树
    if (qr > mid) {
        update(p << 1 | 1, mid + 1, r, ql, qr, k);
    }
    pushup(p); // 向上合并子节点信息
}

// 区间查询操作
// p: 当前节点索引
// l, r: 当前节点代表的区间 [l, r]
// ql, qr: 查询的目标区间 [ql, qr]
ULL query(int p, int l, int r, int ql, int qr) {
    // 如果当前节点区间完全包含在目标区间内
    if (ql <= l && r <= qr) {
        return tree[p].sum;
    }

    pushdown(p, l, r); // 下推懒惰标记

    int mid = l + ((r - l) >> 1);
    ULL res = 0;
    // 如果目标区间与左子树有交集，则递归查询左子树
    if (ql <= mid) {
        res += query(p << 1, l, mid, ql, qr);
    }
    // 如果目标区间与右子树有交集，则递归查询右子树
    if (qr > mid) {
        res += query(p << 1 | 1, mid + 1, r, ql, qr);
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false); // 加速输入输出
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    build(1, 1, n); // 构建线段树，根节点索引为 1，代表区间 [1, n]

    for (int i = 0; i < m; ++i) {
        int op_type;
        std::cin >> op_type;
        if (op_type == 1) {
            ULL x, y, k;
            std::cin >> x >> y >> k;
            update(1, 1, n, x, y, k); // 区间加法
        } else {
            int x, y;
            std::cin >> x >> y;
            std::cout << query(1, 1, n, x, y) << "\n"; // 区间求和
        }
    }

    return 0;
}
