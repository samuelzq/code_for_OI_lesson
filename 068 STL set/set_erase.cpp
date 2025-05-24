/**
 *
 * @File:   set_erase.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-11
 *
 */
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {10, 20, 30, 40, 50};

    std::cout << "原始集合: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 按值删除
    size_t num_erased = s.erase(30);
    if (num_erased > 0) {
        std::cout << "成功删除 30。" << std::endl;
    } else {
        std::cout << "30 不存在。" << std::endl;
    }

    std::cout << "删除 30 后: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 尝试删除不存在的元素
    num_erased = s.erase(100);
    if (num_erased > 0) {
        std::cout << "成功删除 100。" << std::endl;
    } else {
        std::cout << "100 不存在。" << std::endl;
    }

    // 按迭代器删除
    auto it = s.find(10);
    if (it != s.end()) {
        s.erase(it);
        std::cout << "通过迭代器删除 10。" << std::endl;
    }

    std::cout << "删除 10 后: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 删除一个范围 (注意: erase 返回下一个元素的迭代器)
    // 删除从 20 到 40 的元素（不包括 40）
    // auto it_start = s.find(20);
    // auto it_end = s.find(40);
    // if (it_start != s.end() && it_end != s.end()) {
    //     s.erase(it_start, it_end);
    //     std::cout << "删除范围 [20, 40) 后: ";
    //     for (int x : s) {
    //         std::cout << x << " ";
    //     }
    //     std::cout << std::endl;
    // } else {
    //     std::cout << "指定范围不存在。" << std::endl;
    // }

    // 清空集合
    s.clear();
    std::cout << "清空后集合大小: " << s.size() << std::endl;

    return 0;
}
