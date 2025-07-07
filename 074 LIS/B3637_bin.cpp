/**
 * https://www.luogu.com.cn/problem/B3637
 *
 * @File:   B3637_bin.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-08
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> tails; // 维护一个递增序列

    for (int num : nums) {
        // 找到第一个大于等于当前数的位置
        auto it = lower_bound(tails.begin(), tails.end(), num);

        if (it == tails.end()) {
            // 当前数比所有数都大，可以扩展LIS
            tails.push_back(num);
        } else {
            // 替换掉第一个大于等于它的数，保持序列尽可能小
            *it = num;
        }
    }

    cout << tails.size() << endl;

    return 0;
}
