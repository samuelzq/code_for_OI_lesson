#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char str1[11], str2[11], str3[11];

	cin >> str1 >> str2 >> str3;

	if (strlen(str1) == 5 && strlen(str2) == 7 && strlen(str3) == 5)
		cout << "valid" << endl;
	else
		cout << "invalid" << endl;
	return 0;
}