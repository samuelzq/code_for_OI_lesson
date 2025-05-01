#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL f[33];

int main(void)
{
	int n;

	cin >> n;

	f[1] = f[2] = 1;

	for (int i = 3; i <= 30; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	while (n--) {
		int t;

		cin >> t;
		cout << f[t] << endl;
	}
	return 0;
}