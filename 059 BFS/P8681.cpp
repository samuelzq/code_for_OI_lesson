/**
 * https://www.luogu.com.cn/problem/P8681
 *
 * @File:   P8681.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-22
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

// 定义节点结构体
struct Node {
    int node;
    int depth;
};

int main() {
    int n;
    cin >> n;

    vector<long long> weights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }

    queue<Node> q; // 队列存储节点信息
    q.push({1, 1}); // 根节点编号为1，深度为1

    vector<long long> depthSums; // 存储每一层权值和
    int maxDepth = 0;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        int node = curr.node;
        int depth = curr.depth;

        maxDepth = max(maxDepth, depth);

        if (depthSums.size() < depth) {  // 完全二叉树到达新的一层
            depthSums.push_back(weights[node]);
        } else {
            depthSums[depth - 1] += weights[node];
        }

        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;

        if (leftChild <= n) {
            q.push({leftChild, depth + 1});
        }
        if (rightChild <= n) {
            q.push({rightChild, depth + 1});
        }
    }

    long long maxSum = LLONG_MIN;
    int maxDepthIndex = 0;

    for (int i = 0; i < depthSums.size(); ++i) {
        if (depthSums[i] > maxSum) {
            maxSum = depthSums[i];
            maxDepthIndex = i + 1;
        }
    }

    cout << maxDepthIndex << endl;

    return 0;
}
