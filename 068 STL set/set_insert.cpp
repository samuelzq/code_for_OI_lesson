/**
 *
 * @File:   set_init.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-11
 *
 */
#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;

    numbers.insert(10);
    numbers.insert(5);
    numbers.insert(20);
    numbers.insert(5); // 尝试插入重复元素，不会成功

    std::cout << "numbers 中的元素 (插入后): ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // 输出: 5 10 20 (自动排序)

    // insert() 返回一个 std::pair<iterator, bool>
    // bool 值表示是否成功插入
    auto result = numbers.insert(15);
    if (result.second) {
        std::cout << "成功插入 15。" << std::endl;
    } else {
        std::cout << "15 已经存在。" << std::endl;
    }

    result = numbers.insert(5);
    if (result.second) {
        std::cout << "成功插入 5。" << std::endl;
    } else {
        std::cout << "5 已经存在。" << std::endl;
    }

    return 0;
}
