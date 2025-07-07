/**
 * https://www.luogu.com.cn/problem/P1020
 *
 * @File:   P1020.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-08
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> heights;
    int h;
    while (cin >> h) {
        heights.push_back(h);
    }
    int n = heights.size();

    // 第一问：最长不上升子序列长度
    vector<int> dp1(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[j] >= heights[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    int ans1 = *max_element(dp1.begin(), dp1.end());

    // 第二问：最长上升子序列长度
    vector<int> dp2(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[j] < heights[i]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int ans2 = *max_element(dp2.begin(), dp2.end());

    cout << ans1 << endl << ans2 << endl;

    return 0;
}
