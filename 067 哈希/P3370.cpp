/**
 * https://www.luogu.com.cn/problem/P3370
 *
 * @File:   P3370.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-01
 *
 */
#include <bits/stdc++.h>
using namespace std;

const int mod = 1000007;
vector<string> harsh[mod];

int get_harsh(string str)
{
	int h = 0;

	for (char c : str) {
		h = (h + c * 131) % mod;
	}
	return h;
}

int main(void)
{
	int n, cnt;

	cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		int h = get_harsh(str);
		int j = 0;
		for (; j < harsh[h].size(); j++) {
			if (harsh[h][j] == str)
				break;
		}

		if (j == harsh[h].size()) {
			cnt++;
			harsh[h].push_back(str);
		}
	}
	cout << cnt << endl;
	return 0;
}
