#include <stdio.h>  
#include <string.h>  
  
int main() {  
    char str[100] = "Hello, World!";  
    int length = 5;  
    int len = strlen(str);  
    if (len > length) {
    	// �ڽ�β������ַ���������
        str[length] = '\0';    
    }  
    // ���: "Hello"
    printf("%s\n", str);    
    return 0;  
}
