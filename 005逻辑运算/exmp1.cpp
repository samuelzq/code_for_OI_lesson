#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 10;
    int c = 15;

    // 使用逻辑运算符构建条件
    if (a < b && b < c) {
    	cout << "a 小于 b，且 b 小于 c" << endl;
    } else {
        cout << "条件不满足" << endl;
    }

    // 使用逻辑非运算符
    if (!(a < b)) {
        cout << "a 不小于 b" << endl;
    }

    // 使用条件（三元）运算符
    cout << "较大的数是 " << (a > b ? a : b) << endl;

    return 0;
}