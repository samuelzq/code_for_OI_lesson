#include <iostream>

using namespace std;

int main() {
    // 整型
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;

    // 字符型
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of wchar_t: " << sizeof(wchar_t) << " bytes" << endl;

    // 浮点型
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;

    return 0;
}