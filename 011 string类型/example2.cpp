#include <iostream>
#include <string>
using namespace std;

int main() {
    // 定义一个字符串
    string myString = "   Hello, World!   ";

    // 使用substr()方法获取子串
    string substring = myString.substr(1, 5); // 输出: '  Hel'

    // 使用find()方法查找子字符串的位置
    size_t position = myString.find("World"); // 输出: 10

    // 使用replace()方法替换字符串中的子串
    string replacedString = myString.replace(myString.find("World"), 5, "C++"); // 输出: '   Hello, C++!   '

    // 使用erase()方法删除字符串中的字符
    myString.erase(0, 2); // 删除前两个字符
    myString.erase(myString.size() - 2); // 删除最后两个字符
    // 输出: 'Hello, C++!'

    // 输出结果
    cout << "Substring: " << substring
         << "\nPosition: " << position
         << "\nReplaced: " << replacedString << " Size: " << replacedString.size()
         << "\nErased: " << myString << " Size: " << myString.size() << endl;

    return 0;
}