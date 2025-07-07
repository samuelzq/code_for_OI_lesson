/**
 * https://www.luogu.com.cn/problem/P1020
 *
 * @File:   P1020_bin.cpp
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

    // 第一问：最长不上升子序列长度（使用非递增序列）
    vector<int> seq1;
    for (int h : heights) {
        auto it = upper_bound(seq1.begin(), seq1.end(), h, greater<int>());
        if (it == seq1.end()) {
            seq1.push_back(h);
        } else {
            *it = h;
        }
    }
    int ans1 = seq1.size();

    // 第二问：最长上升子序列长度
    vector<int> seq2;
    for (int h : heights) {
        auto it = lower_bound(seq2.begin(), seq2.end(), h);
        if (it == seq2.end()) {
            seq2.push_back(h);
        } else {
            *it = h;
        }
    }
    int ans2 = seq2.size();

    cout << ans1 << endl << ans2 << endl;

    return 0;
}
