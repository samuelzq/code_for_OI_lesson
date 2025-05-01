#include <stdio.h>  
#include <string.h>  
  
int main() {  
    char str[100] = "Hello, World!";  
    int length = 5;  
    int len = strlen(str);  
    if (len > length) {
    	// 在截尾处添加字符串结束符
        str[length] = '\0';    
    }  
    // 输出: "Hello"
    printf("%s\n", str);    
    return 0;  
}
