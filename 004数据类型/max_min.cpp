#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

int main() {
    // 整型
    cout << "int:         " << INT_MIN << " to " << INT_MAX << endl;
    cout << "short:       " << SHRT_MIN << " to " << SHRT_MAX << endl;
    cout << "long:        " << LONG_MIN << " to " << LONG_MAX << endl;
    cout << "long long:   " << LLONG_MIN << " to " << LLONG_MAX << endl;

    // 字符型
    cout << "char:        " << static_cast<int>(CHAR_MIN) << " to " << static_cast<int>(CHAR_MAX) << endl;
    cout << "wchar_t:     " << static_cast<int>(WCHAR_MIN) << " to " << static_cast<int>(WCHAR_MAX) << endl;

    // 浮点型
    cout << "float:       " << FLT_MIN << " to " << FLT_MAX << endl;
    cout << "double:      " << DBL_MIN << " to " << DBL_MAX << endl;
    cout << "long double: " << LDBL_MIN << " to " << LDBL_MAX << endl;

    return 0;
}