#include <iostream>

using namespace std;

char str[102];
int main(void)
{
	int i;
	cout << "请输出字符串：";
	cin >> str;

	i = 0;
	while (str[i])
		i++;

	cout << "输入的字符串是：" << str << " 长度是：" << i << endl;
	return 0;
}