/**
 * https://www.luogu.com.cn/problem/P2249
 *
 * @File:   P2249.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define N   1000006
int a[N];

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < m; i++) {
		int q;
		int *pos;

		scanf("%d", &q);
		pos = lower_bound(a, a + n, q);

		// 判断是否找到目标值
		if (pos != a + n && *pos == q) {
			int index = pos - a + 1; // 计算索引
			printf("%d ", index);
		} else {
			printf("-1 ");
		}
	}
	printf("\n");
	return 0;
}
