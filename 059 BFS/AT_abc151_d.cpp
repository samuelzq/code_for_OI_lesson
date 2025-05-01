/**
 * https://www.luogu.com.cn/problem/AT_abc151_d
 *
 * @File:   AT_abc151_d.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-22
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    int maxDist = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右四个方向

    for (int startRow = 0; startRow < h; ++startRow) {
        for (int startCol = 0; startCol < w; ++startCol) {
            if (grid[startRow][startCol] == '.') {
                vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
                queue<pair<int, int>> q;

                dist[startRow][startCol] = 0;
                q.push({startRow, startCol});

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    for (int i = 0; i < 4; ++i) {
                        int newRow = curr.first + directions[i][0];
                        int newCol = curr.second + directions[i][1];

                        if (newRow >= 0 && newRow < h && newCol >= 0 && newCol < w &&
                            grid[newRow][newCol] == '.' && dist[newRow][newCol] == INT_MAX) {
                            dist[newRow][newCol] = dist[curr.first][curr.second] + 1;
                            q.push({newRow, newCol});
                        }
                    }
                }

                for (int i = 0; i < h; ++i) {
                    for (int j = 0; j < w; ++j) {
                        if (grid[i][j] == '.' && dist[i][j] != INT_MAX) {
                            maxDist = max(maxDist, dist[i][j]);
                        }
                    }
                }
            }
        }
    }

    cout << maxDist << endl;

    return 0;
}
