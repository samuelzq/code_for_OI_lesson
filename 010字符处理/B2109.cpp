#include <iostream>

using namespace std;

int main(void)
{
	char c;
	int cnt = 0;

	while (cin >> c) {  // EOF
		if ('0' <= c && c <= '9')
			cnt++;
	}
	cout << cnt << endl;
    return 0;
}
