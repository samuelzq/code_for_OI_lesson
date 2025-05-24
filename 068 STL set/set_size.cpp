/**
 *
 * @File:   set_size.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-11
 *
 */
#include <iostream>
#include <set>

int main() {
    std::set<char> chars = {'a', 'b', 'c'};

    std::cout << "chars 集合的大小: " << chars.size() << std::endl;

    if (chars.empty()) {
        std::cout << "chars 集合是空的。" << std::endl;
    } else {
        std::cout << "chars 集合不为空。" << std::endl;
    }

    chars.clear();
    if (chars.empty()) {
        std::cout << "chars 集合现在是空的。" << std::endl;
    }

    return 0;
}
