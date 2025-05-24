/**
 * https://www.luogu.com.cn/problem/P1059
 *
 * @File:   P1059.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-10
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	set<int> s;
	int n, x;
	cin >> n;

	while (n--) {
		cin >> x;
		s.insert(x);
	}
	cout << s.size() << endl;
	for (auto num : s)
		cout << num << " ";
	return 0;
}
