#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int l;
	char str1[111];

	cin >> str1;
	l = strlen(str1);
	str1[l - 1] = '5';
	cout << str1 << endl;
	return 0;
}