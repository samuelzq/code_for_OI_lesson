#include <bits/stdc++.h>
using namespace std;

#define LL  long long

int dl(LL n)
{
    int l = 0;
    while (n) {
    	l++;
    	n /= 10;
	}
	return l;
}

int main(void)
{
	LL n;

	cin >> n;
	for (LL d = sqrt(n); d > 0; d--) {
		if (n % d == 0) {
			cout << dl(n / d) << endl;
			break;
		}
	}
	return 0;
}
