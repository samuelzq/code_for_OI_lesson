/**
 * https://www.luogu.com.cn/problem/B3631
 *
 * @File:   B3631i_arr.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-05
 *
 */
#include <bits/stdc++.h>
using namespace std;
int Node[1000006] = {0};

int main(void)
{
	int n;

	cin >> n;
	while (n--) {
		int ops, x;

		cin >> ops >> x;
		if (ops == 1) {
			int y;
			cin >> y;
			Node[y] = Node[x];
			Node[x] = y;
		} else if (ops == 2) {
			cout << Node[x] << '\n';
		} else if (ops == 3) {
			int next = Node[x];
			if (next) {
				Node[x] = Node[next];
				Node[next] = 0;
			}
		}
	}
	return 0;
}
