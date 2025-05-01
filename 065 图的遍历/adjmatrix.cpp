/**
 *
 * @File:   adjmatrix.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-21
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 递归DFS实现
void dfsMatrixRecursive(int u, vector<vector<bool>>& matrix, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " "; // 访问节点

    for (int v = 0; v < matrix.size(); ++v) {
        if (matrix[u][v] && !visited[v]) {
            dfsMatrixRecursive(v, matrix, visited);
        }
    }
}

// 非递归DFS实现（使用栈）
void dfsMatrixIterative(int start, vector<vector<bool>>& matrix, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << u << " "; // 访问节点

        // 注意邻接点入栈顺序，保证与递归顺序一致
        for (int v = matrix.size() - 1; v >= 0; --v) {
            if (matrix[u][v] && !visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}

// BFS实现
void bfsMatrix(int start, vector<vector<bool>>& matrix, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // 访问节点

        for (int v = 0; v < matrix.size(); ++v) {
            if (matrix[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// 构建邻接矩阵
vector<vector<bool>> buildAdjMatrix(int n, const vector<pair<int, int>>& edges, bool directed = false) {
    vector<vector<bool>> matrix(n + 1, vector<bool>(n + 1, false));   // bool matrix[n + 1][n + 1]

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        matrix[u][v] = true;
        if (!directed) {
            matrix[v][u] = true; // 无向图需要对称设置
        }
    }

    return matrix;
}

int main() {
    // 示例：5个节点，6条边
    int n = 5;
    vector<pair<int, int>> edges = {{1,2}, {1,3}, {2,4}, {3,4}, {3,5}, {4,5}};

    // 构建邻接矩阵（无向图）
    vector<vector<bool>> matrix = buildAdjMatrix(n, edges);

    // 初始化访问数组
    vector<bool> visited(n + 1, false);

    cout << "DFS (Recursive with matrix): ";
    dfsMatrixRecursive(1, matrix, visited);
    cout << endl;

    // 重置visited数组
    fill(visited.begin(), visited.end(), false);

    cout << "DFS (Iterative with matrix): ";
    dfsMatrixIterative(1, matrix, visited);
    cout << endl;

    // 重置visited数组
    fill(visited.begin(), visited.end(), false);

    cout << "BFS (with matrix): ";
    bfsMatrix(1, matrix, visited);
    cout << endl;

    return 0;
}
