#include <iostream>  
#include <string>  
  
int main() {  
    std::string str = "Hello, World!";  
    int length = str.length();  

	// ��ȡ�ַ��������������һ���ַ�
	// �õ�: "Hello, World"
    str = str.substr(0, length - 1);  
    std::cout << str << std::endl;    
    return 0;  
}
