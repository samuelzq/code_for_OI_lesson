#include <iostream>

using namespace std;

int main() {
    int a, b, c;

    cout << "请输入三个整数，用空格分隔：";
    cin >> a >> b >> c; // 在一个语句中读取三个整数
    cout << "你输入的整数分别是：" << a << ", " << b << ", " << c << endl;
    return 0;
}