/**
 *
 * @File:   bfs.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-16
 *
 */
#include <iostream>
#include <queue>  // 使用 STL 的 queue

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int data;                // 节点存储的数据
    TreeNode* left;          // 左子树指针
    TreeNode* right;         // 右子树指针

    // 构造函数
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 插入节点（假设按照二叉搜索树规则插入）
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);  // 如果树为空，创建新节点作为根
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);  // 插入左子树
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);  // 插入右子树
    }
    // 如果数据相等，可以选择不插入（二叉搜索树不允许重复值）
    return root;
}

// 广度优先遍历（层序遍历）
void breadthFirstTraversal(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;  // 使用 STL 的 queue
    q.push(root);        // 将根节点入队

    while (!q.empty()) {
        TreeNode* current = q.front();  // 获取队首节点
        q.pop();                        // 出队当前节点
        cout << current->data << " ";   // 访问当前节点

        // 将左右子节点入队（如果存在）
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

// 主函数：测试二叉树的基本操作和广度优先遍历
int main() {
    TreeNode* root = nullptr;  // 初始化空树

    // 插入节点，构建二叉搜索树
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // 输出广度优先遍历结果
    cout << "广度优先遍历: ";
    breadthFirstTraversal(root);
    cout << endl;

    return 0;
}
