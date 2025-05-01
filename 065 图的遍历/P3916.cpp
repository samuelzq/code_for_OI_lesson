/**
 * https://www.luogu.com.cn/problem/P3916
 *
 * @File:   P3916.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-21
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define N  100005
int a[N] = {0};
vector<int> p[N];

void dfs(int x, int y)
{
	if (a[x] < y)
		a[x] = y;
	for (int i = 0, sz = p[x].size(); i < sz; i++) {
		if (a[p[x][i]] < y) {
			a[p[x][i]] = y;
			dfs(p[x][i], y);
		}
	}
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[v].push_back(u);
	}

	for (int i = n; i > 0; i--)
		dfs(i, i);

	for (int i = 1; i < n; i++)
		cout << a[i] << ' ';
	cout << a[n] << endl;
	return 0;
}