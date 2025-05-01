/**
 * https://www.luogu.com.cn/problem/B3674
 *
 * @File:   B3678.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-28
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	vector<string> str;
	string wd;

	while (cin >> wd)
		str.push_back(wd);

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < str[i].size(); j++) {
			char c;
			if (j % 2 == 0)
				c = toupper(str[i][j]);
			else
				c = tolower(str[i][j]);
			cout << c;
		}
		cout << ' ';
	}
	cout << endl;
	return 0;
}
