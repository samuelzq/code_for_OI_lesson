#include <iostream>  
  
int main() {  
    char ch;  
    int shift;  
  
    std::cout << "请输入一个字符：";  
    std::cin >> ch;  
  
    std::cout << "请输入移位的数量：";  
    std::cin >> shift;  
  
    // 确保移位后的字符仍然是一个有效的ASCII字符  
    if (ch >= 'a' && ch <= 'z') {  
        // 处理小写字母的移位  
        ch = (ch - 'a' + shift) % 26 + 'a'; // 循环移位，保持在'a'-'z'范围内  
    } else if (ch >= 'A' && ch <= 'Z') {  
        // 处理大写字母的移位  
        ch = (ch - 'A' + shift) % 26 + 'A'; // 循环移位，保持在'A'-'Z'范围内  
    } else {  
        // 对于非字母字符，直接进行移位（可能会导致无效的ASCII字符）  
        ch = static_cast<char>(ch + shift);  
    }  
  
    std::cout << "移位后的字符是：" << ch << std::endl;  
  
    return 0;  
}
