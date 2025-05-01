#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    int data;                // 节点存储的数据
    struct TreeNode *left;   // 左子树指针
    struct TreeNode *right;  // 右子树指针
} TreeNode;

// 创建新节点
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点（假设按照二叉搜索树规则插入）
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);  // 如果树为空，创建新节点作为根
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);  // 插入左子树
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);  // 插入右子树
    }
    // 如果数据相等，可以选择不插入（二叉搜索树不允许重复值）
    return root;
}

// 前序遍历（根 -> 左 -> 右）
void preOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);       // 访问根节点
    preOrderTraversal(root->left);   // 遍历左子树
    preOrderTraversal(root->right);  // 遍历右子树
}

// 中序遍历（左 -> 根 -> 右）
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);    // 遍历左子树
    printf("%d ", root->data);       // 访问根节点
    inOrderTraversal(root->right);   // 遍历右子树
}

// 后序遍历（左 -> 右 -> 根）
void postOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);  // 遍历左子树
    postOrderTraversal(root->right); // 遍历右子树
    printf("%d ", root->data);       // 访问根节点
}

// 主函数：测试二叉树的基本操作
int main() {
    TreeNode* root = NULL;  // 初始化空树

    // 插入节点，构建二叉搜索树
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // 输出遍历结果
    printf("前序遍历: ");
    preOrderTraversal(root);
    printf("\n");

    printf("中序遍历: ");
    inOrderTraversal(root);
    printf("\n");

    printf("后序遍历: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
