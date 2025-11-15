/**
 * https://www.luogu.com.cn/problem/P1330
 *
 * @File:   P1330.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-08-26
 *:
 **/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭 C 和 C++ 的标准流同步，加快 I/O
    cin.tie(nullptr); // 解除 cin 与 cout 的绑定，提高输入输出效率

    int n, m;
    if (!(cin >> n >> m)) return 0; // 读入点数和边数，若读取失败直接退出

    // 使用邻接表存储无向图
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // 因为是无向图，所以两边都要加
    }

    vector<int> color(n + 1, -1); // 颜色数组，-1 表示未染色，0/1 表示两种颜色
    long long ans = 0; // 答案累加器

    // 遍历每个点，处理每个连通分量
    for (int s = 1; s <= n; ++s) {
        if (color[s] != -1) continue; // 已经染色过的点跳过

        queue<int> q;
        color[s] = 0; // 给当前分量的起点染色为 0
        int cnt[2] = {1, 0}; // cnt[0]、cnt[1] 分别统计两种颜色的点数
        q.push(s);

        // BFS 遍历当前连通分量
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) { // 如果该点未染色
                    color[v] = color[u] ^ 1; // 染成相反的颜色（0->1, 1->0）
                    ++cnt[color[v]]; // 对应颜色计数加 1
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    // 如果相邻两点颜色相同，说明不是二分图
                    cout << "Impossible\n";
                    return 0; // 直接结束
                }
            }
        }

        // 对于二分图的一个连通分量，选颜色类较小的一边即可最优覆盖
        // 孤立点分量 (c0=1, c1=0) 的 min 为 0，不会影响结果
        ans += min(cnt[0], cnt[1]);
    }

    cout << ans << "\n"; // 输出最少封锁点数
    return 0;
}
