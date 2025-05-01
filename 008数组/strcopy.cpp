#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char src[] = "Hello, world!"; // 源字符串
    char dest[50]; // 目标字符数组，足够大以容纳源字符串

    // 使用 strcpy 复制源字符串到目标字符数组
    strcpy(dest, src);

    // 输出目标字符数组中的字符串
    cout << "Copied string: " << dest << endl;

    return 0;
}