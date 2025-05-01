/**
 *
 * @File:   adjlist.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-21
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 递归实现DFS
void dfsRecursive(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " "; // 访问节点，可根据题目要求修改

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsRecursive(v, adj, visited);
        }
    }
}

// 非递归实现DFS（使用栈）
void dfsIterative(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << u << " "; // 访问节点

        // 注意：邻接点入栈顺序与递归版本相反
        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
            int v = *it;
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}


void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // 访问节点

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// 构建邻接表
vector<vector<int>> buildAdjList(int n, const vector<pair<int, int>>& edges, bool directed = false) {
    vector<vector<int>> adj(n + 1); // 假设节点编号从1开始

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u); // 无向图需要双向添加
        }
    }

    return adj;
}

int main() {
    // 示例：5个节点，6条边
    int n = 5;
    vector<pair<int, int>> edges = {{1,2}, {1,3}, {2,4}, {3,4}, {3,5}, {4,5}};

    // 构建邻接表（无向图）
    vector<vector<int>> adj = buildAdjList(n, edges);

    // 初始化访问数组
    vector<bool> visited(n + 1, false);

    cout << "DFS (Recursive): ";
    dfsRecursive(1, adj, visited); // 从节点1开始
    cout << endl;

    // 重置visited数组
    fill(visited.begin(), visited.end(), false);

    cout << "DFS (Iterative): ";
    dfsIterative(1, adj, visited);
    cout << endl;

    // 重置visited数组
    fill(visited.begin(), visited.end(), false);

    cout << "BFS: ";
    bfs(1, adj, visited);
    cout << endl;

    return 0;
}
