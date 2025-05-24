/**
 * https://www.luogu.com.cn/problem/P1379
 *
 * @File:   P1379.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-14
 *
 */
#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

string target = "123804765"; // 目标状态

int bfs(string start) {
    queue<string> q;
    unordered_set<string> visited; // 记录已访问状态
    q.push(start);
    visited.insert(start);

    int steps = 0;
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            string cur = q.front();
            q.pop();

            if (cur == target) return steps; // 找到解

            int pos = cur.find('0');
            int x = pos / 3, y = pos % 3;

            // 四个方向移动
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

                string next = cur;
                swap(next[pos], next[nx * 3 + ny]); // 交换位置

                if (!visited.count(next)) { // 新状态未访问过
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    string start;
    cin >> start;
    cout << bfs(start) << endl;
    return 0;
}
