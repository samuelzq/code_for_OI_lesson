/**
 * https://www.luogu.com.cn/problem/P1102
 *
 * @File:   p1102_e.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-09
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, c;
    long long cnt;

    cin >> n >> c;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cnt = 0;
    for (int i = 0; i < n;) {
        long long d = a[i];
        auto range_d = equal_range(a.begin(), a.end(), d);
        long long x = distance(range_d.first, range_d.second); // 数组中有x个d

        i += x;

        auto range_dc = equal_range(a.begin(), a.end(), d + c);
        long long z = distance(range_dc.first, range_dc.second); // 数组中有 z 个d + c

        cnt += x * z;
    }
    cout << cnt << endl;
    return 0;
}
