#include <iostream>

int main() {
    // 外层循环控制行数
    for (int i = 0; i < 5; ++i) {
        // 内层循环控制列数
        for (int j = 0; j < 5; ++j) {
            std::cout << "* "; // 打印星号和一个空格
        }
        std::cout << std::endl; // 换行
    }
    return 0;
}