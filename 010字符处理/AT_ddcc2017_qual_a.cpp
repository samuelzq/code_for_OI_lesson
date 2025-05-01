#include <iostream>
using namespace std;

int main(void)
{
	char str[6];

	cin >> str;

	if (str[0] == str[1] && str[2] == str[3] && str[1] != str[2])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
    return 0;
}