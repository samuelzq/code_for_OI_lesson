/**
 * https://www.luogu.com.cn/problem/P1918
 *
 * @File:   P1918.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2024-08-21
 *
 **/
#include <bits/stdc++.h>
using namespace std;

struct bolling {
	int num;
	int idx;
} b[100010];

bool cmp(struct bolling &a, struct bolling &b)
{
	return a.num < b.num;
}

int bin_search(struct bolling *b, int n, int key)
{
	int l, r;

	l = 0;
	r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (b[mid].num == key)
			return b[mid].idx;
		else if (b[mid].num > key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return 0;
}

int main(void)
{
	int n, q;

	scanf("%d", &n);
	// 每个位置可以击中的保龄球的个数是没有排序的
	// 由于需要输出的是序号，因此需要同时保留个数和位置
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i].num);
		b[i].idx = i + 1;
	}
	sort(b, b + n, cmp); // 排序后，二分法查找

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int k;
		scanf("%d", &k);
		printf("%d\n", bin_search(b, n, k));
	}
	return 0;
}

