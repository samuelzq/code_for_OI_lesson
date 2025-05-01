/**
 * https://www.luogu.com.cn/problem/P1918
 *
 * @File:   P1918.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct bolling {
    int num;
    int idx;
} b[100010];

int main() {
    int n, q;

    scanf("%d", &n);
    // 读取保龄球的数量和序号
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i].num);
        b[i].idx = i + 1;
    }

    // 按保龄球的数量排序
    sort(b, b + n, [](const bolling &a, const bolling &b) {
        return a.num < b.num;
    });

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);

        // 使用 std::lower_bound 查找第一个大于等于 k 的位置
        auto it = lower_bound(b, b + n, k, [](const bolling &a, int key) {
            return a.num < key;
        });

        // 检查是否找到精确匹配
        if (it != b + n && it->num == k) {
            printf("%d\n", it->idx);  // 输出原始序号
        } else {
            printf("0\n");  // 没找到
        }
    }
    return 0;
}

