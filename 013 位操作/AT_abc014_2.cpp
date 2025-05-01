#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, out;

	cin >> n >> m;

	out = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (m & (1 << i))
			out += a;
	}

	cout << out << endl;
    return 0;
}