#include <iostream>  
  
int main() {  
    char ch;  
    std::cout << "������һ���ַ���";  
    std::cin >> ch;  
  
    if (ch >= 'a' && ch <= 'z') {  
        ch = ch - 'a' + 'A'; // ��Сд��ĸת��Ϊ��д��ĸ  
        std::cout << ch << " �Ǵ�д��ĸ��" << std::endl;  
    } else if (ch >= 'A' && ch <= 'Z') {  
        ch = ch - 'A' + 'a'; // ����д��ĸת��ΪСд��ĸ  
        std::cout << ch << " ��Сд��ĸ��" << std::endl;  
    } else {  
        std::cout << ch << " �Ȳ��Ǵ�д��ĸҲ����Сд��ĸ��" << std::endl;  
    }  
  
    return 0;  
}
