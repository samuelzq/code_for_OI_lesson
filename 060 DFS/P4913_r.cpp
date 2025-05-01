/**
 * https://www.luogu.com.cn/problem/P4913
 *
 * @File:   P4913_r.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-23
 *
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int left;
    int right;
};

int maxDepth = 0;

void dfs(const vector<TreeNode>& tree, int node, int depth) {
    if (node == 0) {
        return;
    }
    // 更新最大深度
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    // 递归遍历左子树
    dfs(tree, tree[node].left, depth + 1);
    // 递归遍历右子树
    dfs(tree, tree[node].right, depth + 1);
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> tree(n + 1); // 使用1-based索引

    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].left >> tree[i].right;
    }

    dfs(tree, 1, 1); // 从根节点1开始，初始深度为1

    cout << maxDepth << endl;

    return 0;
}
