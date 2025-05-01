#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    unsigned int n, m;

    cin >> n;

    m = ((n & 0xffff) << 16) | (n >> 16);
	cout << m << endl;
    return 0;
}
