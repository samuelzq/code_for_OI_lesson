/**
 * https://www.luogu.com.cn/problem/P1147
 *
 * @File:   P1147.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-20
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<long long> prefix_sum(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + i;
    }

    int left = 1, right = 2;
    while (right <= m) {
        long long current_sum = prefix_sum[right] - prefix_sum[left - 1];
        if (current_sum == m && right - left + 1 >= 2) {
            cout << left << " " << right << endl;
            left++;
            right++;
        } else if (current_sum < m) {
            right++;
        } else {
            left++;
        }
    }

    return 0;
}
