#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	long long int n, f1, f2, f;

	cin >> n;

	f = f1 = f2 = 1;

	for (int i = 2; i <= n; i++) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}
	cout << f << endl;
	return 0;
}
