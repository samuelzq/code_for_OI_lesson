#include <iostream>
#include <string>
using namespace std;

int main() {
    // 定义一个字符串
    string myString = "Hello, World!";

    // 访问字符串中的字符
    char firstChar = myString[0];       // 输出: 'H'
    char lastChar = myString[myString.size() - 1]; // 输出: '!'

    // 字符串长度
    size_t length = myString.length(); // 输出: 13

    // 字符串连接
    string greeting = "Hello";
    string name = "Alice";
    string combined = greeting + ", " + name + "!"; // 输出: 'Hello, Alice!'

    // 字符串的复制
    string repeatedString = myString + ' ' + myString + ' ' + myString; // 输出: 'Hello, World! Hello, World! Hello, World!'

    // 输出结果
    cout << "First char: " << firstChar << "\n Last char: " << lastChar
         << "\n Length: "   << length
         << "\n Combined: " << combined
         << "\n Repeated: " << repeatedString << endl;

    return 0;
}