/**
 * https://www.luogu.com.cn/problem/P2055
 *
 * @File:   P2055.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-08-30
 *
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 55;

int n;
int is_student[MAXN];    // 是否是学生
int go_home[MAXN];       // 是否回家
int know[MAXN][MAXN];    // 认识关系矩阵
bool need_bed[MAXN];     // 是否需要床铺
bool bed_available[MAXN];// 床是否可用

vector<int> graph[MAXN]; // 二分图邻接表
int match[MAXN];         // match[j] = i: 床j被人i占了
bool visited[MAXN];      // DFS访问标记

// DFS函数：尝试为左边节点u寻找匹配
bool dfs(int u) {
    for (int v : graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

// 匈牙利算法求最大匹配
int hungarian() {
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++) {
        if (need_bed[i]) {
            memset(visited, false, sizeof(visited));
            if (dfs(i)) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // 初始化
        cin >> n;
        memset(need_bed, 0, sizeof(need_bed));
        memset(bed_available, 0, sizeof(bed_available));
        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }

        // 读入学生身份
        for (int i = 0; i < n; i++) {
            cin >> is_student[i];
        }

        // 读入回家情况
        for (int i = 0; i < n; i++) {
            cin >> go_home[i];
        }

        // 读入认识关系
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> know[i][j];
            }
        }

        // 预处理：确定需要床的人和可用的床
        int need_count = 0;
        for (int i = 0; i < n; i++) {
            // 需要床的人：不是学生，或者是学生但不回家
            if (!is_student[i] || (is_student[i] && !go_home[i])) {
                need_bed[i] = true;
                need_count++;
            }

            // 可用的床：是学生且（回家或者不回家都可以）
            // 回家的学生：床空出来可用
            // 不回家的学生：床可用（但主人可能睡自己的床或别人的床）
            if (is_student[i]) {
                bed_available[i] = true;
            }
        }

        // 建图：为每个需要床的人添加可睡的床
        for (int i = 0; i < n; i++) {
            if (!need_bed[i]) continue;

            for (int j = 0; j < n; j++) {
                if (!bed_available[j]) continue;

                // 如果i认识j，或者i就是j自己（自己肯定认识自己的床）
                if (know[i][j] || i == j) {
                    graph[i].push_back(j);
                }
            }
        }

        // 计算最大匹配数
        int match_count = hungarian();

        // 输出结果
        if (match_count == need_count) {
            cout << "^_^" << endl;
        } else {
            cout << "T_T" << endl;
        }
    }
    return 0;
}
