/**
 *
 * @File:   P1714_2p.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-20
 *
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int max_luck = INT_MIN;

    for (int k = 1; k <= m; ++k) { // 遍历所有可能的长度
        int current_luck = 0;
        for (int i = 0; i < k; ++i) { // 计算第一个窗口内的和
            current_luck += p[i];
        }
        max_luck = max(max_luck, current_luck);

        for (int i = k; i < n; ++i) { // 滑动窗口
            current_luck = current_luck - p[i - k] + p[i]; // 更新最大的和
            max_luck = max(max_luck, current_luck);
        }
    }

    cout << max_luck << endl;

    return 0;
}
