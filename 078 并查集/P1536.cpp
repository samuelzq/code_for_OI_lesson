/**
 * https://www.luogu.com.cn/problem/P1536
 *
 * @File:   P1536.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-01
 *
 */
#include <bits/stdc++.h>
using namespace std;

int pa[1010];
int s[1010];

int find(int x)
{
	return (pa[x] == x) ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	int px, py;

	px = find(x);
	py = find(y);

	if (px == py)
		return;

	pa[py] = px;
}

int main(void)
{
	int n, m;

	while (1) {
		cin >> n;

		if (!n)
			break;

		cin >> m;

		for (int i = 0; i <= n; i++) {
			pa[i] = i;
			s[i] = 0;
		}

		// 利用并查集将相互连接的城市归纳到同一个集合
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			unite(x, y);
		}

		// 统计集合数量，需要新修的道路的数目比集合数少一
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			s[find(i)] = 1;
		}
		for (int i = 1; i <= n; i++)
			cnt += s[i];
		cout << cnt - 1 << endl;
	}
	return 0;
}
