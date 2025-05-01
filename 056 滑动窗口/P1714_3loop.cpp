/**
 * https://www.luogu.com.cn/problem/P1714
 *
 * @File:   P1714_3loop.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-20
 *
 * 此解法会TLE
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

    for (int k = 1; k <= m; ++k) { // 枚举所有可能的长度
        for (int i = 0; i <= n - k; ++i) { // 遍历所有可能的起点
            int current_luck = 0;
            for (int j = i; j < i + k; ++j) {
                current_luck += p[j];
            }
            max_luck = max(max_luck, current_luck);
        }
    }

    cout << max_luck << endl;

    return 0;
}

