/**
 *
 * @File:   set_init.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-11
 *
 */
#include <iostream>
#include <set>
#include <string>
#include <vector> // 为了后续例子中使用

int main() {
    // 声明一个存储整数的 set
    std::set<int> myIntSet;

    // 声明一个存储字符串的 set
    std::set<std::string> myStringSet;

    // 也可以在声明时使用初始化列表进行初始化 (C++11 及更高版本)
    std::set<double> myDoubleSet = {3.14, 1.618, 2.718, 1.618};
    // 注意：1.618 会被忽略，因为 set 只存储唯一元素

    std::cout << "myDoubleSet 中的元素: ";
    for (double val : myDoubleSet) {
        std::cout << val << " ";
    }
    std::cout << std::endl; // 输出: 1.618 2.718 3.14

    return 0;
}
