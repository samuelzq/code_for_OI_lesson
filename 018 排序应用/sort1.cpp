#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    int a[5] = {4, 2, 5, 1, 3};
    sort(a, a + 5); // 使用默认的operator<进行升序排序

    for (int n : a) {
        cout << n << ' '; // 输出: 1 2 3 4 5
    }

    return 0;
}