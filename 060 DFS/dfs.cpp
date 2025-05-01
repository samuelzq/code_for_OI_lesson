/**
 *
 * @File:   dfs.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-29
 *
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " "; // 访问根节点
    preorderTraversal(root->left); // 遍历左子树
    preorderTraversal(root->right); // 遍历右子树
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left); // 遍历左子树
    cout << root->val << " "; // 访问根节点
    inorderTraversal(root->right); // 遍历右子树
}

void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left); // 遍历左子树
    postorderTraversal(root->right); // 遍历右子树
    cout << root->val << " "; // 访问根节点
}

int main() {
    /* 创建一个简单的二叉树
     *     1
     *    / \
     *   2   3
     *  / \
     * 4   5
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "前序遍历：";
    preorderTraversal(root);
    cout << endl;

    cout << "中序遍历：";
    inorderTraversal(root);
    cout << endl;

    cout << "后序遍历：";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
