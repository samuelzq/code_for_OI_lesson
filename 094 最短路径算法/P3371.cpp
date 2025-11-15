/**
 * https://www.luogu.com.cn/problem/P3371
 *
 * @File:   P3371.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-10-25
 *
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<int> dist;

void bellmanFord(int n, int s) {
    dist.assign(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i < n; i++) {
        bool updated = false;
        for (const auto &e : edges) {
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    edges.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    bellmanFord(n, s);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }

    return 0;
}
