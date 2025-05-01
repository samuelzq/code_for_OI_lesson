#include <iostream>
using namespace std;

int main(void)
{
	int x;

	cin >> x;

	cout << "Today, I ate " << x << " apple";
	if (x > 1)
		cout << "s." << endl;
	else
		cout << "." << endl;
	return 0;
}