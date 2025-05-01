/**
 * https://www.luogu.com.cn/problem/P1030
 *
 * @File:   P1030.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-23
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 根据中序遍历和后序遍历构建二叉树
// inorder 是中序遍历的字符串
// postorder 是后序遍历的字符串
// inStart 是当前子树在中序遍历字符串中的起始索引
// inEnd 是当前子树在中序遍历字符串中的结束索引
// postStart 是当前子树在后序遍历字符串中的起始索引
// postEnd 是当前子树在后序遍历字符串中的结束索引
string buildTree(string &inorder, string &postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return "";
    }

    char rootVal = postorder[postEnd];     // 从后序遍历的末尾获取根节点
    int rootIndex = inorder.find(rootVal); // 查找根节点在中序遍历中的位置
    int leftSize = rootIndex - inStart;    // 计算左子树的大小

    return rootVal +
           buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1) +
           buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    string inorder, postorder;
    cin >> inorder >> postorder;

    cout << buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1) << endl;

    return 0;
}
