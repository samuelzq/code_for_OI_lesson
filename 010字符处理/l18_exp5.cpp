#include <iostream>
#include <cctype>  
  
int main() {  
    char ch;  
    std::cout << "请输入一个字母：";  
    std::cin >> ch;  
  
    if (std::isupper(ch)) {
        std::cout << ch << " 是大写字母。" << std::endl;  
    } else if (std::islower(ch)) {  
        std::cout << ch << " 是小写字母。" << std::endl;  
    } else {  
        std::cout << ch << " 既不是大写字母也不是小写字母。" << std::endl;  
    }  

    return 0;  
}
