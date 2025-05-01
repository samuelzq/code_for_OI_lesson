/**
 * https://www.luogu.com.cn/problem/P1739
 *
 * @File:   P1739.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-31
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	string str;
	stack<char> s;
	bool flag = true;

	cin >> str;
	for (char c : str) {
		if (c == '(')         // 将左括号入栈
			s.push(c);
		else if (c == ')') {  // 每遇到一个右括号，便尝试在栈中找一个左括号
			if (s.empty()) {  // 当前栈空，没有与之匹配的左括号
				flag = false;
				break;
			} else {
				s.pop();
			}
	  }
	}

	if (!s.empty())    // 当前栈中有失配的左括号
		flag = false;

	if (flag == false)
		cout << "NO\n";
	else
		cout << "YES\n";
	cout << endl;
	return 0;
}
