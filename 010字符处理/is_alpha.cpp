#include <iostream>
#include <cctype> // 包含 isalpha 函数的头文件

using namespace std;

int main() {
    char ch;
    cout << "请输入一个字符: ";
    cin >> ch; // 读取一个字符

    // 检查字符是否是字母
    if (isalpha(ch)) {
        cout << ch << " 是一个字母." << endl;
    } else {
        cout << ch << " 不是一个字母." << endl;
    }

    return 0;
}