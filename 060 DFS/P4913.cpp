/**
 * https://www.luogu.com.cn/problem/P4913
 *
 * @File:   P4913.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-23
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode*> nodes(n + 1); // 节点从 1 开始编号
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode(i);
    }

    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        if (left != 0) {
            nodes[i]->left = nodes[left];
        }
        if (right != 0) {
            nodes[i]->right = nodes[right];
        }
    }

    cout << maxDepth(nodes[1]) << endl; // 根节点编号为 1

    // 释放内存
    for (int i = 1; i <= n; i++) {
        delete nodes[i];
    }

    return 0;
}
