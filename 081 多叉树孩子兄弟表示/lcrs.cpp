/**
 *
 * @File:   lcrs.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-07-13
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 树节点结构
struct TreeNode {
    char data;
    TreeNode* firstChild;  // 指向第一个孩子
    TreeNode* nextSibling; // 指向下一个兄弟
    TreeNode(char val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

// 使用孩子兄弟表示法构建多叉树
TreeNode* buildTree() {
    /*
    构建如下多叉树：
          A
        / | \
       B  C  D
      / \    |
     E   F   G
    */
    TreeNode* root = new TreeNode('A');

    // A的孩子是B、C、D
    TreeNode* b = new TreeNode('B');
    TreeNode* c = new TreeNode('C');
    TreeNode* d = new TreeNode('D');
    root->firstChild = b;
    b->nextSibling = c;
    c->nextSibling = d;

    // B的孩子是E、F
    TreeNode* e = new TreeNode('E');
    TreeNode* f = new TreeNode('F');
    b->firstChild = e;
    e->nextSibling = f;

    // D的孩子是G
    TreeNode* g = new TreeNode('G');
    d->firstChild = g;

    return root;
}

// 前序遍历（递归）
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrderTraversal(root->firstChild);
    preOrderTraversal(root->nextSibling);
}

// 后序遍历（递归）
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->firstChild);
    cout << root->data << " ";
    postOrderTraversal(root->nextSibling);
}

// 层序遍历（广度优先）
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";

        // 将当前节点的所有孩子加入队列
        TreeNode* child = node->firstChild;
        while (child != nullptr) {
            q.push(child);
            child = child->nextSibling;
        }
    }
}

// 计算树的高度
int treeHeight(TreeNode* root) {
    if (root == nullptr) return 0;

    int maxHeight = 0;
    TreeNode* child = root->firstChild;

    while (child != nullptr) {
        maxHeight = max(maxHeight, treeHeight(child));
        child = child->nextSibling;
    }

    return maxHeight + 1;
}

// 查找节点
TreeNode* findNode(TreeNode* root, char target) {
    if (root == nullptr) return nullptr;
    if (root->data == target) return root;

    TreeNode* found = findNode(root->firstChild, target);
    if (found) return found;

    return findNode(root->nextSibling, target);
}

// 释放树内存
void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->firstChild);
    freeTree(root->nextSibling);
    delete root;
}

int main() {
    TreeNode* root = buildTree();

    cout << "前序遍历: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "后序遍历: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "层序遍历: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "树的高度: " << treeHeight(root) << endl;

    char target = 'F';
    TreeNode* node = findNode(root, target);
    if (node) {
        cout << "找到节点 " << target << endl;
    } else {
        cout << "未找到节点 " << target << endl;
    }

    freeTree(root);
    return 0;
}
