#include <iostream>
#include <cstring>

using namespace std;

char str[102];
int main(void)
{
	cout << "请输出字符串：";
	cin >> str;

	cout << "输入的字符串是：" << str << " 长度是：" << strlen(str) << endl;
	return 0;
}