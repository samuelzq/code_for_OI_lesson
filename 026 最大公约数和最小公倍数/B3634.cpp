#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return (b) ? gcd(b, a % b) : a;
}

int main(void)
{
	long long int a, b, g;

	cin >> a >> b;
	g = gcd(a, b);

	cout << g << ' ' << a * b / g << endl;
	return 0;
}