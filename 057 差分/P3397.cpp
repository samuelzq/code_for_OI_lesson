/**
 * https://www.luogu.com.cn/problem/P3397
 *
 * @File:   P3397.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-23
 *
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005; // 假设最大格子大小为 1000

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化差分数组
    vector<vector<int>> diff(MAXN, vector<int>(MAXN, 0));

    // 处理每块地毯
    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 更新差分数组
        diff[x1][y1] += 1;
        diff[x2 + 1][y1] -= 1;
        diff[x1][y2 + 1] -= 1;
        diff[x2 + 1][y2 + 1] += 1;
    }

    // 计算二维前缀和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    // 输出结果
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
