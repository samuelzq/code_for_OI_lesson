/**
 * https://www.luogu.com.cn/problem/P4779
 *
 * @File:   P4779.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-10-25
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, s;
vector<pair<int, int>> graph[MAXN];
int dist[MAXN];
bool visited[MAXN];

void dijkstra() {
    // 初始化距离
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;

    // 小根堆：存储 (距离, 节点)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        // 取出当前距离最小的节点
        int u = pq.top().second;
        pq.pop();

        // 如果这个节点已经处理过，跳过
        if (visited[u]) continue;
        visited[u] = true;

        // 遍历所有邻居
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            // 松弛操作
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
