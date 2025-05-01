#include <iostream>

using namespace std;

int a[1002];

int main(void)
{
    int n, i;

    cin >> n;

    i = 0;

    a[i++] = n;
    while (n > 1)
    {
        if (n % 2)
            n = n * 3 + 1;
        else
            n /= 2;
        a[i++] = n;
    }
	//cout << i << " Times\n";
    while (i > 1)
    {
        cout << a[i - 1] << ' ';
        i--;
    }
    cout << a[0] << endl;
    return 0;
}
