/**
 * https://www.luogu.com.cn/problem/P2105
 *
 * @File:   p2105.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-05
 *
 */
#include <iostream>
#include <vector>

using namespace std;

const int M = 20005;
int attacked_rows[M] = {0};
int attacked_cols[M] = {0};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> queens(k);

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        queens[i].first = x;
        queens[i].second = y;
        attacked_rows[x] = 1;
    }

    long long total_cells = (long long)n * m;
    long long attacked_cells = 0;

    for (int i = 1; i <= n; ++i) {
    	if (attacked_rows[i]) {  // 当前行有皇后
            attacked_cells += m;
            continue;
        }

        // 遍历每个皇后，检测每个皇后对当前行的影响
        for (const auto& queen : queens) {
            int qx = queen.first;
            int qy = queen.second;
            int d1 = qx - qy;
            int d2 = qx + qy;
            int left, right;   // 主副对角线上的皇后

            // 首先检测列上的影响
            if (attacked_cols[qy] != i)
                attacked_cells++;
            attacked_cols[qy] = i;

            // 检测对角线上的影响
            if (qx < i) {  // 当前行上方的皇后
                left = d2 - i;
                right = i - d1;
            } else {       // 当前行下方的皇后
                left = i - d1;
                right = d2 - i;
            }
            if (left >= 1 && left <= m) {
                if (attacked_cols[left] != i)
                    attacked_cells++;
                attacked_cols[left] = i;
            }
            if (right >= 1 && right <= m) {
                if (attacked_cols[right] != i)
                    attacked_cells++;
                attacked_cols[right] = i;
            }
        }
    }

    cout << total_cells - attacked_cells << endl;

    return 0;
}


