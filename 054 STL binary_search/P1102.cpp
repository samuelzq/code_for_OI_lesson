/**
 * https://www.luogu.com.cn/problem/P1102
 *
 * @File:   P1102.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL arr[200004];

int main(void)
{
    int n, c;
    LL cnt;

    cin >> n >> c;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    cnt = 0;
    for (int i = 0; i < n;) {
        LL b, x = 0;
        LL *pos;
        b = arr[i];
        x = upper_bound(arr, arr + n, b) - arr - i;   // 数组中有x个b

        i += x;
        pos = lower_bound(arr, arr + n, b + c);
        if (pos == arr + n) {
            continue;       // 数组中没有b + c
        }

        int y = upper_bound(arr, arr + n, b + c) - pos;  // 数组中有 y 个b + c
        cnt += x * y;
    }
    cout << cnt << endl;
    return 0;
}
