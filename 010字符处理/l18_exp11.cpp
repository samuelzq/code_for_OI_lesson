#include <iostream>  
#include <string>  
  
int main() {  
    std::string str = "Hello, World!";  
    int length = str.length();  

	// 截取字符串，不包括最后一个字符
	// 得到: "Hello, World"
    str = str.substr(0, length - 1);  
    std::cout << str << std::endl;    
    return 0;  
}
