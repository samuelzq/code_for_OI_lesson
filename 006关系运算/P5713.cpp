#include <iostream>

using namespace std;

int main(void)
{
    int n, l, s;

    cin >> n;

    l = n * 5;
    s = n * 3 + 11;

    if (l > s)
        cout << "Luogu" << endl;
    else
        cout << "Local" << endl;
    return 0;
}
