/**
 * https://www.luogu.com.cn/problem/B3614
 *
 * @File:   B3614.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-31
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	stack<unsigned long long> s;
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		while (!s.empty())
			s.pop();
		while (n--) {
			string ops;

			cin >> ops;
			if (ops == "push") {
				unsigned long long d;
				cin >> d;
				s.push(d);
			} else if (ops == "query") {
				if (!s.empty())
					cout << s.top() << '\n';
				else
					cout << "Anguei!\n";
			} else if (ops == "size") {
				cout << s.size() << '\n';
			} else if (ops == "pop") {
				if (s.empty())
					cout << "Empty\n";
				else
					s.pop();
			}
		}
	}
	cout << endl;
	return 0;
}
