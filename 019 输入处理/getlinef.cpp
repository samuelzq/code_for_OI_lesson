#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    // 从标准输入（通常是键盘）读取一行
    getline(std::cin, line);

    cout << "你输入的是: " << line << endl;

    return 0;
}
