#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main(void)
{
	int x, y, z;
	int g1, g2;

	cin >> x >> y >> z;
	g1 = gcd(x, y);
	g2 = gcd(y, z);

	cout << gcd(g1, g2) << endl;
	return 0;
}