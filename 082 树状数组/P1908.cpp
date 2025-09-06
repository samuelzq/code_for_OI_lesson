/**
 * https://www.luogu.com.cn/record/226213137
 *
 * @File:   P1908.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-07-26
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// 树状数组的实现
const int MAXN = 500005;
long long tree[MAXN];
int n_unique; // 离散化后的最大值

int lowbit(int x) {
    return x & (-x);
}

void update(int idx, int val) {
    for (; idx <= n_unique; idx += lowbit(idx)) {
        tree[idx] += val;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= lowbit(idx)) {
        sum += tree[idx];
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sorted_a[i] = a[i];
    }

    // 1. 离散化
    std::sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(std::unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

    n_unique = sorted_a.size();
    std::map<int, int> discrete_map;
    for (int i = 0; i < n_unique; ++i) {
        discrete_map[sorted_a[i]] = i + 1;
    }

    long long total_inversions = 0;

    // 2. 使用树状数组进行逆序对计数
    // 从右到左遍历，统计在它之后有多少个比它小的数
    for (int i = n - 1; i >= 0; --i) {
        int discrete_val = discrete_map[a[i]];

        // 查询在它之后有多少个比它小的数
        total_inversions += query(discrete_val - 1);

        // 标记当前数已出现
        update(discrete_val, 1);
    }

    /*
    // 另一种从左到右遍历的方法
    // 这种方法和分析中的思路一致
    std::fill(tree, tree + MAXN, 0); // 重置树状数组
    long long total_inversions_2 = 0;

    for (int i = 0; i < n; ++i) {
        int discrete_val = discrete_map[a[i]];

        // 查询在它之前有多少个比它大的数
        total_inversions_2 += (query(n_unique) - query(discrete_val));

        // 标记当前数已出现
        update(discrete_val, 1);
    }
    */

    std::cout << total_inversions << std::endl;

    return 0;
}
