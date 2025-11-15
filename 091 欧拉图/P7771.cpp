/**
 * https://www.luogu.com.cn/problem/P7771
 *
 * @File:   P7771.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-09-07
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];  // 邻接表
int in_degree[MAXN], out_degree[MAXN];  // 入度和出度
int current_edge[MAXN];  // 当前弧优化，记录每个点当前访问到第几条边
vector<int> path;  // 存储欧拉路径

// Hierholzer算法
void dfs(int u) {
    for (int &i = current_edge[u]; i < graph[u].size(); ) {
        int v = graph[u][i];
        i++;  // 移动到下一条边
        dfs(v);
    }
    path.push_back(u);  // 后序记录
}

int main() {
    int n, m;
    cin >> n >> m;

    // 读入图数据
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        out_degree[u]++;
        in_degree[v]++;
    }

    // 对每个点的出边按字典序排序（为了得到最小字典序）
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // 检查是欧拉回路还是欧拉路径
    int start = 1, cnt_start = 0, cnt_end = 0;
    bool is_circuit = true;

    for (int i = 1; i <= n; i++) {
        if (out_degree[i] != in_degree[i]) {
            is_circuit = false;
            if (out_degree[i] - in_degree[i] == 1) {
                cnt_start++;
                start = i;  // 找到起点
            } else if (in_degree[i] - out_degree[i] == 1) {
                cnt_end++;
            }
        }
    }

    // 如果不是欧拉回路，需要检查欧拉路径条件
    if (!is_circuit) {
        if (!(cnt_start == 1 && cnt_end == 1)) {
            // 不存在欧拉路径（虽然题目保证存在，但这里为了完整性）
            cout << "No" << endl;
            return 0;
        }
    } else {
        // 对于欧拉回路，找编号最小的有出边的点作为起点
        for (int i = 1; i <= n; i++) {
            if (out_degree[i] > 0) {
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
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }

    return 0;
}
