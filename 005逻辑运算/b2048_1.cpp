#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c;

	cin >> a >> b >> c;
	if (a > b && a > c)
	{
		cout << a;
	}
	else if (b > a && b > c)
	{
		cout << b;
	}
	else
	{
		cout << c;
	}
	cout << endl;
	return 0;
}