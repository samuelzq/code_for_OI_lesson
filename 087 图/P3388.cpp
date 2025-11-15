/**
 * https://www.luogu.com.cn/problem/P3388
 *
 * @File:   P3388.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-08-24
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 20005; // 最大顶点数

vector<int> graph[MAXN]; // 邻接表存储图
int dfn[MAXN], low[MAXN]; // 时间戳数组和追溯值数组
int timer = 0; // 全局时间计数器
bool isCut[MAXN]; // 标记是否为割点
int n, m; // 顶点数和边数

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++timer; // 初始化当前节点的时间戳和追溯值
    int child = 0; // 记录子树数量（用于根节点判断）

    for (int v : graph[u]) { // 遍历所有邻接节点
        if (v == fa) continue; // 跳过父节点

        if (!dfn[v]) { // 如果v未被访问过
            tarjan(v, u); // 递归访问子节点
            low[u] = min(low[u], low[v]); // 回溯后更新low[u]

            // 判断非根节点u是否为割点
            if (low[v] >= dfn[u] && fa != 0) {
                isCut[u] = true;
            }
            child++; // 增加子树计数
        } else { // 如果v已被访问过，且不是父节点（回边）
            low[u] = min(low[u], dfn[v]); // 通过回边更新追溯值
        }
    }

    // 单独判断根节点是否为割点
    if (fa == 0 && child >= 2) {
        isCut[u] = true;
    }
}

int main() {
    cin >> n >> m;

    // 读入图数据
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 无向图，双向添加
    }

    // 初始化数组
    for (int i = 1; i <= n; i++) {
        dfn[i] = low[i] = 0;
        isCut[i] = false;
    }

    // 对每个未访问的节点执行Tarjan算法
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            timer = 0; // 重置计时器（虽然题目保证连通，但习惯性重置）
            tarjan(i, 0); // 0表示没有父节点（根节点）
        }
    }

    // 统计割点数量
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (isCut[i]) cnt++;
    }

    // 输出结果
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (isCut[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
