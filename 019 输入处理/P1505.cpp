#include <iostream>

using namespace std;

int main(void)
{
    int n;
    string str;

	getline(cin, str);

	n = str.length();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			n--;
	}
    cout << n << endl;
    return 0;
}
