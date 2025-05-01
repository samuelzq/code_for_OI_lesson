#include <iostream>
  
int main() {  
    char ch;  
    std::cout << "请输入一个字符：";  
    std::cin >> ch;

    if (ch >= 'a' && ch <= 'z') {
        std::cout << ch << " 是小写字母。" << std::endl;  
    } else if (ch >= 'A' && ch <= 'Z') {
        std::cout << ch << " 是大写字母。" << std::endl;
    } else {  
        std::cout << ch << " 既不是大写字母也不是小写字母。" << std::endl;
    }

    return 0;
}
