#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int a = 60;      // 60 = 0011 1100
    int b = 13;      // 13 = 0000 1101
    int c = 0;
    bitset<8> bin;

    bin = a;
    cout << "a 的值是：" << a << " 二进制表示：" << bin << " 十六进制表示： 0x" << hex << a << dec << endl;
    bin = b;
    cout << "b 的值是：" << b << " 二进制表示：" << bin << endl;
    bin = -a;
    cout << "-a 的值是：" << -a << " 二进制表示：" << bin << endl;

    c = a & b;        // 12 = 0000 1100
    bin = c;
    cout << "a & b 的值是：" << c << " 二进制表示：" << bin << endl;

    c = a | b;             // 61 = 0011 1101
    bin = c;
    cout << "a | b 的值是：" << c << " 二进制表示：" << bin << endl;

    c = a ^ b;             // 49 = 0011 0001
    bin = c;
    cout << "a ^ b 的值是：" << c << " 二进制表示：" << bin << endl;

    c = ~a;                // -61 = 1100 0011
    bin = c;
    cout << "~a 的值是：" << c << " 二进制表示：" << bin << endl;

    c = a << 2;            // 240 = 1111 0000
    bin = c;
    cout << "a << 2 的值是：" << c << " 二进制表示：" << bin << endl;

    c = a >> 2;            // 15 = 0000 1111
    bin = c;
    cout << "a >> 2 的值是：" << c << " 二进制表示：" << bin << endl;


    bin = -1 * a;
    cout << "a 值是：" << -a  << " 二进制表示：" << bin << endl;

    c = -1 * a >> 2;            // 15 = 0000 1111
    bin = c;
    cout << "-a >> 2 的值是：" << c << " 二进制表示：" << bin << endl;

    return 0;
}
