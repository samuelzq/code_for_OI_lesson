#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return n >= 2;
}

bool isLucky(int n)
{
	while (n) {
		if (isPrime(n) == false)
			return false;
		n /= 10;
	}
	return true;
}

int main()
{
	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (isLucky(i))
			cout << i << endl;
	}
	return 0;
}