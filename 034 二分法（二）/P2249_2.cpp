/**
 * https://www.luogu.com.cn/problem/P2249
 *
 * @File:   P2249_2.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-08-31
 *
 */
#include <bits/stdc++.h>
using namespace std;

int a[1000006] = {0};

int left_bound(int a[], int len, int target)
{
	int l, r, mid, ans;

	l = 1;
	r = len;
	ans = -1;

	while (l <= r) {
		mid = l + (r - l) / 2;

		if (a[mid] == target) {
			ans = mid;
			r = mid - 1;
		} else if (a[mid] > target) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	while (m--) {
		int q;
		cin >> q;
		cout << left_bound(a, n, q);
		if (m > 0)
			cout << ' ';
		else
			cout << endl;
	}
	return 0;
}
