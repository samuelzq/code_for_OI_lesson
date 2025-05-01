#include <iostream>
#include <algorithm> // 包含 std::sort bits/stdc++.h

int main() {
    // 定义一个整数数组
    int array[] = {5, 2, 8, 1, 9, 3};
    const int size = sizeof(array) / sizeof(array[0]); // 计算数组的大小

    // 使用 std::sort 对数组进行排序
    std::sort(array, array + size);

    // 打印排序后的数组
    for (int i = 0; i < size; ++i) {  
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
