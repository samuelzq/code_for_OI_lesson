/**
 * https://www.luogu.com.cn/problem/P1223
 *
 * @File:   p1223.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-02
 *
 */
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> people(n); // pair<接水时间, 原始编号>

    for (int i = 0; i < n; ++i) {
        cin >> people[i].first;
        people[i].second = i + 1; // 编号从1开始
    }

    // 按照接水时间从小到大排序
    sort(people.begin(), people.end());

    // 输出排队顺序
    for (int i = 0; i < n; ++i) {
        cout << people[i].second;
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    // 计算平均等待时间
    double total_wait = 0;
    double current_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            current_sum += people[i-1].first;
            total_wait += current_sum;
        }
    }

    double average = total_wait / n;
    cout << fixed << setprecision(2) << average << endl;

    return 0;
}
