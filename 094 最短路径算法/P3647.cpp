/**
 * https://www.luogu.com.cn/problem/B3647
 *
 * @File:   P3647.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-10-25
 *
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化距离矩阵
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // 对角线为0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // 读入边
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);  // 处理重边，取最小值
        dist[v][u] = dist[u][v];
    }

    // Floyd 算法
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << -1 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
