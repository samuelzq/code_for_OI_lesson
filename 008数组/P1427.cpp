#include <iostream>

using namespace std;

unsigned int a[105];

int main(void)
{
    int n;

    n = 0;
    while(1) {
        cin >> a[n];
        if (a[n] == 0)
            break;
        n++;
    }

    for (int i = n - 1; i > 0; i--)
        cout << a[i] << ' ';
    cout << a[0] << endl;
    return 0;
}
