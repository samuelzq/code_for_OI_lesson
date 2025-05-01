#include <iostream>
#include <algorithm>

int main() {  
    // 定义一个字符串数组
    std::string array[] = {"apple", "aanana", "cherry", "date"};
    const int size = sizeof(array) / sizeof(array[0]);

    // 使用自定义比较函数对数组进行排序
    std::sort(array, array + size);

    // 打印排序后的数组
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << '\n';
    }
    std::cout << std::endl;

    return 0;
}