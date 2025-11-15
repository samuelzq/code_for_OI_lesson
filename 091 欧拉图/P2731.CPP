/**
 * https://www.luogu.com.cn/problem/P2731
 *
 * @File:   P2731.CPP
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-09-07
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 505;  // 题目中顶点编号最大到500

vector<int> graph[MAXN];  // 邻接表
int degree[MAXN];         // 每个顶点的度数
int current_edge[MAXN];   // 当前弧优化
vector<int> path;         // 存储欧拉路径

// 使用邻接矩阵来记录边的数量（处理重边）
int edge_count[MAXN][MAXN];

void dfs(int u) {
    for (int &i = current_edge[u]; i < graph[u].size(); ) {
        int v = graph[u][i];
        i++;  // 移动到下一条边
        // 检查边是否还存在
        if (edge_count[u][v] > 0) {
            edge_count[u][v]--;
            edge_count[v][u]--;
            dfs(v);
        }
    }
    path.push_back(u);  // 后序记录
}

int main() {
    int m;
    cin >> m;

    int max_node = 0;
    int min_node = MAXN;

    // 读入边数据
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
        edge_count[u][v]++;
        edge_count[v][u]++;

        max_node = max(max_node, max(u, v));
        min_node = min(min_node, min(u, v));
    }

    // 对每个点的邻接点按字典序排序
    for (int i = 1; i <= max_node; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // 寻找起点
    int start = min_node;
    int odd_count = 0;
    vector<int> odd_nodes;

    for (int i = min_node; i <= max_node; i++) {
        if (degree[i] % 2 == 1) {
            odd_count++;
            odd_nodes.push_back(i);
        }
    }

    // 如果有奇点，选择编号最小的奇点作为起点
    if (odd_count > 0) {
        start = odd_nodes[0];
        // 确保选择最小的奇点（虽然排序后第一个就是最小的）
        for (int node : odd_nodes) {
            if (node < start) {
                start = node;
            }
        }
    } else {
        // 欧拉回路，选择编号最小的有边的点
        for (int i = min_node; i <= max_node; i++) {
            if (degree[i] > 0) {
                start = i;
                break;
            }
        }
    }

    // 运行Hierholzer算法
    dfs(start);

    // 反转路径（因为是后序记录的）
    reverse(path.begin(), path.end());

    // 输出结果
    for (int node : path) {
        cout << node << endl;
    }

    return 0;
}
