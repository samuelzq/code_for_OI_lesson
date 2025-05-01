/**
 * https://www.luogu.com.cn/problem/P1427
 *
 * @File:   P1427.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-31
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	stack<int> s;
	int t;

	while (1) {
		cin >> t;
		if (t == 0)
			break;
		s.push(t);
	}

	t = s.top();
	s.pop();
	while (!s.empty()) {
		cout << t << ' ';
		t = s.top();
		s.pop();
	}
	cout << t << endl;
	return 0;
}
