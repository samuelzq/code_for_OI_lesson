/**
 * https://www.luogu.com.cn/problem/P3370
 *
 * @File:   p3370.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-10
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	set<string> unique_strings;
	string str;
	int n;

	cin >> n;
	while (n--) {
		cin >> str;
		unique_strings.insert(str);
	}
	cout << unique_strings.size();
	return 0;
}
