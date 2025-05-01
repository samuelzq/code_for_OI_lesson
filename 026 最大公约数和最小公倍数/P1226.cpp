#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL fastPower(LL a, LL b, LL p)
{
	if (b == 0)
		return 1;

	LL res = fastPower(a, b / 2, p);

	if (b & 1)
        return (res * res % p) * a % p;
    else
        return (res * res) % p;
}

int main(void)
{
    LL a, b, p;

    cin >> a >> b >> p;

    cout << a << '^' << b << " mod " << p << '=' << fastPower(a, b, p) << endl;
    return 0;
}