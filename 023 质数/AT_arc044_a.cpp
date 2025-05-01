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

int main()
{
	int n;
	cin >> n;

	if (isPrime(n)) {
		cout << "Prime" << endl;
	} else if ((n & 1) && (n % 5) && (n % 3) && (n > 1)) {
		cout << "Prime" << endl;
	} else {
		cout << "Not Prime" << endl;
	}
	return 0;
}