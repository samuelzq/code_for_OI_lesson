#include <iostream>  
  
int main() {  
    char ch;  
    int shift;  
  
    std::cout << "������һ���ַ���";  
    std::cin >> ch;  
  
    std::cout << "��������λ��������";  
    std::cin >> shift;  
  
    // ȷ����λ����ַ���Ȼ��һ����Ч��ASCII�ַ�  
    if (ch >= 'a' && ch <= 'z') {  
        // ����Сд��ĸ����λ  
        ch = (ch - 'a' + shift) % 26 + 'a'; // ѭ����λ��������'a'-'z'��Χ��  
    } else if (ch >= 'A' && ch <= 'Z') {  
        // �����д��ĸ����λ  
        ch = (ch - 'A' + shift) % 26 + 'A'; // ѭ����λ��������'A'-'Z'��Χ��  
    } else {  
        // ���ڷ���ĸ�ַ���ֱ�ӽ�����λ�����ܻᵼ����Ч��ASCII�ַ���  
        ch = static_cast<char>(ch + shift);  
    }  
  
    std::cout << "��λ����ַ��ǣ�" << ch << std::endl;  
  
    return 0;  
}
