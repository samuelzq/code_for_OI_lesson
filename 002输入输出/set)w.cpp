#include <iostream>
#include <iomanip> // 包含用于格式化的头文件

int main() {
    std::cout << std::setw(10) << 123 << std::endl; // 输出宽度为10，默认右对齐
    std::cout << std::setw(10) << std::left << 456 << std::endl; // 左对齐
    std::cout << std::setw(10) << std::setfill('*') << 789 << std::endl; // 使用'*'作为填充字符
    return 0;
}