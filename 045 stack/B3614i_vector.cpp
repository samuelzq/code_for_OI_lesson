/**
 * https://www.luogu.com.cn/problem/B3614
 *
 * @File:   B3614i_vector.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-31
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	vector<unsigned long long> s;
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		s.clear();
		while (n--) {
			string ops;

			cin >> ops;
			if (ops == "push") {
				unsigned long long d;
				cin >> d;
				s.push_back(d);
			} else if (ops == "query") {
				size_t sz = s.size();
				if (sz)
					cout << s[sz - 1] << '\n';
				else
					cout << "Anguei!\n";
			} else if (ops == "size") {
				cout << s.size() << '\n';
			} else if (ops == "pop") {
				if (s.empty())
					cout << "Empty\n";
				else
					s.pop_back();
			}
		}
	}
	cout << endl;
	return 0;
}
