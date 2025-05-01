/**
 * https://www.luogu.com.cn/problem/P1824
 *
 * @File:   P1824.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-03-19
 *
 */
#include <bits/stdc++.h>

using namespace std;

int a[100005];
int n, c;

	bool enough(int g)  // 统计按照当前间隔g，可以安置多少头牛
{
    int b, s = 1;

    b = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - b >= g) {
            s++;
            b = a[i];
        }
    }

    return s >= c;
}

int main(void)
{
    int r, l, mid, ans;

    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    l = 1;
    r = a[n - 1] - a[0];

    while (l <= r) {
    //cout << l << ' ' << r << endl;
        mid = l + (r - l) / 2;
      //  cout << mid << endl;
        if (enough(mid)) {  // 右半边继续查找
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

