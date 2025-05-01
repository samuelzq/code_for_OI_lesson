/**
 * https://www.luogu.com.cn/problem/P3853
 *
 * @File:   P3853.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-03-31
 *
 */
#include <bits/stdc++.h>

using namespace std;

int l, n, k;
int a[100005];

bool fine(int g)  // 计算当前间隔g，需要新增的路标数量是否满足要求
{
    int cnt = 0;

    for (int i = 1; i <= n; i++)
        cnt += (a[i] - a[i - 1] - 1) / g;
    //cout << cnt << endl;
    return (cnt <= k);
}

int main(void)
{
    int ll, rr, ans;

    cin >> l >> n >> k;
    a[0] = 0;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    a[n] = l;

    ll = 1;
    rr = l;
    ans = 0;
    while (ll <= rr) {
        int mid = ll + (rr - ll) / 2;

        //cout << ll << ' ' << mid << ' ' << rr << endl;
        if (fine(mid)) {  // 左半边继续查找
            ans = mid;
            rr = mid - 1;
        } else {   // 间隔太小，需要的路标太多，右半边查找
            ll = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

