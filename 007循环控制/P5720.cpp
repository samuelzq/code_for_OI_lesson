#include <iostream>

using namespace std;

int main(void)
{
	int a, i;

	cin >> a;
	i = 1;
	while (a > 1) {
		i++;
		a /= 2;
	}
	cout << i << endl;
	return 0;
}
