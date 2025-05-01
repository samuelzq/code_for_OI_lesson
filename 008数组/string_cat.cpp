#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char dest[50];
    const char src[] = " World!";

	// 使用 strcpy 将 "Hello" 复制到 dest
    strcpy(dest, "Hello");
    // 使用 strcat 将 " World!" 追加到 dest
    strcat(dest, src);

    cout << dest << endl;  // 输出: Hello World!

    return 0;
}