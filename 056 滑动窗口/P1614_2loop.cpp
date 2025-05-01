/**
 * https://www.luogu.com.cn/problem/P1614
 *
 * @File:   P1614.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-19
 *
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // 读取 n 和 m

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // 读取 n 个刺痛值
    }

    int current_sum = 0;
    int min_sum = INT_MAX;

    // 遍历所有的子区间
    for (int i = 0; i <= n - m; i++) {
        current_sum = 0;

        // 求当前子区间的和
        for (int j = i; j < i + m; j++) {
            current_sum += arr[j];
        }
        min_sum = min(min_sum, current_sum); // 记录最小值
    }

    cout << min_sum << endl; // 输出结果
    return 0;
}


