/**
 * https://www.luogu.com.cn/problem/P1439
 *
 * @File:   P1439.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-12
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p1(n), p2(n);
    // 读取两个排列
    for (int i = 0; i < n; i++) cin >> p1[i];
    for (int i = 0; i < n; i++) cin >> p2[i];

    // 建立p1中元素到位置的映射
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[p1[i]] = i;
    }

    // 将p2转换为p1中的位置序列
    vector<int> seq;
    for (int num : p2) {
        seq.push_back(pos[num]);
    }

    // 在位置序列上求LIS
    vector<int> lis;
    for (int x : seq) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << lis.size() << endl;
    return 0;
}
