#include <iostream>  
  
int main() {  
    char ch;  
    std::cout << "请输入一个字符：";  
    std::cin >> ch;  
  
    if (ch >= 'a' && ch <= 'z') {  
        ch = ch - 'a' + 'A'; // 将小写字母转换为大写字母  
        std::cout << ch << " 是大写字母。" << std::endl;  
    } else if (ch >= 'A' && ch <= 'Z') {  
        ch = ch - 'A' + 'a'; // 将大写字母转换为小写字母  
        std::cout << ch << " 是小写字母。" << std::endl;  
    } else {  
        std::cout << ch << " 既不是大写字母也不是小写字母。" << std::endl;  
    }  
  
    return 0;  
}
