#include <iostream>
using namespace std;

#define LL long long

LL fib(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main(void)
{
	int n;

	cin >> n;
	cout << fib(n) << endl;
	return 0;
}