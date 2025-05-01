#include <iostream>

using namespace std;

int main(void)
{
    int n, out;

    cin >> n;

    if (!(n % 400) || (!(n % 4) && (n % 100)))  // 注意逻辑短路
        cout << 1;
    else
        cout << 0;
    cout << endl;
    return 0;
}