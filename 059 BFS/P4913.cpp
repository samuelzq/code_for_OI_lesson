/**
 * https://www.luogu.com.cn/problem/P4913
 *
 * @File:   P4913.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-22
 *
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
    int n;
    cin >> n;

    // 使用邻接表存储树结构
    vector<pair<int, int>> tree(n + 1); // tree[i] 表示节点 i 的左右子节点

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        tree[i] = {l, r};
    }

    // BFS 计算深度
    queue<pair<int, int>> q; // {节点编号, 当前深度}
    q.push({1, 1}); // 根节点深度为 1

    int max_depth = 0;

    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();

        // 更新最大深度
        max_depth = max(max_depth, depth);

        // 将左右子节点加入队列
        if (tree[node].first != 0) {
            q.push({tree[node].first, depth + 1});
        }
        if (tree[node].second != 0) {
            q.push({tree[node].second, depth + 1});
        }
    }

    cout << max_depth << endl;

    return 0;
}
