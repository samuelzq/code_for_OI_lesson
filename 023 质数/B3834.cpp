#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, c;
	cin >> a;
	c = 0;

	for (int i = 1; i * i <= a; i++) {
		if (a % i == 0)
			c++;
	}
	cout << c << endl;
	return 0;
}
