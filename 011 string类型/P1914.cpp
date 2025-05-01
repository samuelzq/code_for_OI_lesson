#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	string str;

	cin >> n >> str;
	for (int i = 0; i < str.length(); i++) {
		char c;
		c = (str[i] - 'a' + n) % 26 + 'a';
		str[i] = c;
	}
	cout << str << endl;
	return 0;
}