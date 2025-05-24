/**
 *
 * @File:   set_find.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-11
 *
 */
#include <iostream>
#include <set>

int main() {
    std::set<std::string> fruits = {"apple", "banana", "cherry", "grape"};

    // 使用 count() 查找
    if (fruits.count("apple")) {
        std::cout << "集合中包含 'apple'。" << std::endl;
    } else {
        std::cout << "集合中不包含 'apple'。" << std::endl;
    }

    if (fruits.count("orange")) {
        std::cout << "集合中包含 'orange'。" << std::endl;
    } else {
        std::cout << "集合中不包含 'orange'。" << std::endl;
    }

    std::cout << "-------------------" << std::endl;

    // 使用 find() 查找
    auto it = fruits.find("banana");
    if (it != fruits.end()) {
        std::cout << "使用 find() 找到 'banana'，其值为: " << *it << std::endl;
    } else {
        std::cout << "使用 find() 未找到 'banana'。" << std::endl;
    }

    it = fruits.find("kiwi");
    if (it != fruits.end()) {
        std::cout << "使用 find() 找到 'kiwi'，其值为: " << *it << std::endl;
    } else {
        std::cout << "使用 find() 未找到 'kiwi'。" << std::endl;
    }

    return 0;
}
