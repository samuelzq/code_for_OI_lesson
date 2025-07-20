/**
 * https://www.luogu.com.cn/problem/P1551
 *
 * @File:   P1551.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-07-01
 *
 */
#include <iostream>
using namespace std;

const int MAXN = 5005;
int parent[MAXN];

// 查找根节点（带路径压缩）
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 路径压缩
    }
    return parent[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // 加速cin/cout

    int n, m, p;
    cin >> n >> m >> p;

    // 初始化并查集
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 处理亲戚关系
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA; // 合并集合
        }
    }

    // 处理查询
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
