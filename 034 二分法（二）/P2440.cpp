/**
 * https://www.luogu.com.cn/problem/P2440
 *
 * @File:   P2440.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-03-31
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n, k;
int l[100005];

bool fine(int len)
{
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += l[i] / len;
    }

    return cnt >= k;
}

int main(void)
{
    int maxl, ll, rr, ans;

    cin >> n >> k >> l[0];
    maxl = l[0];

    for (int i = 1; i < n; i++) {
        cin >> l[i];
        if (maxl < l[i])
            maxl = l[i];
    }

    ans = 0;
    ll = 1;
    rr = maxl;
    while (ll <= rr) {
        int mid = ll + (rr - ll) / 2;

        if (fine(mid)) {
            ans = mid;    // 记录每一个可能的有边界
            ll = mid + 1;
        } else {
            rr = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

