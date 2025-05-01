#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    // 检查字符串是否为空
    if (str.empty()) {
        cout << "The string is empty." << endl;
    } else {
        cout << "The string is not empty." << endl;
    }

    // 给字符串赋值
    str = "Hello, World!";

    // 再次检查字符串是否为空
    if (str.empty()) {
        cout << "The string is still empty." << endl;
    } else {
        cout << "The string is not empty now." << endl;
    }

    // 清空字符串
    str.clear();

    // 检查字符串是否为空（应为空）
    if (str.empty()) {
        cout << "The string is empty after calling clear()." << endl;
    } else {
        cout << "The string is not empty after calling clear()." << endl;
    }

    return 0;
}