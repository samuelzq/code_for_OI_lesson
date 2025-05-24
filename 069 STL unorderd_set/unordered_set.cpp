/**
 *
 * @File:   unordered_set.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-15
 *
 */
#include <iostream>        // 用于标准输入/输出操作 (std::cout, std::endl)
#include <string>          // 用于使用 std::string
#include <unordered_set>   // std::unordered_set 的头文件
#include <vector>          // 仅用于将元素收集到 vector 的示例（非核心）

int main() {
    // --- 第一部分: 整数类型的基本操作 ---
    std::cout << "--- 第一部分: std::unordered_set<int> 的基本操作 ---\n";

    // 1. 创建一个存储整数的无序集合
    std::unordered_set<int> numbers;
    std::cout << "初始集合大小: " << numbers.size() << std::endl; // 应该为 0

    // 2. 插入元素
    std::cout << "\n插入元素: 10, 20, 10 (重复), 30...\n";
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10); // 尝试插入重复元素；它将被忽略。
    numbers.insert(30);
    std::cout << "插入后的集合大小: " << numbers.size() << std::endl; // 应该为 3 (10, 20, 30)
    std::cout << "\n'numbers' 中的元素（顺序不保证，可能每次运行都不同）:\n";
    for (const int& num : numbers) { // 基于范围的 for 循环
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 3. 检查元素是否存在
    std::cout << "\n检查元素是否存在:\n";
    if (numbers.count(20)) { // count() 如果元素存在则返回 1，否则返回 0
        std::cout << "20 存在于集合中。\n";
    } else {
        std::cout << "20 不存在于集合中。\n";
    }

    // 使用 find() 通常更受青睐，因为它返回一个迭代器
    if (numbers.find(40) == numbers.end()) { // end() 是指向最后一个元素之后的迭代器
        std::cout << "40 不存在于集合中。\n";
    } else {
        std::cout << "40 存在于集合中。\n";
    }

    // 4. 删除元素
    std::cout << "\n删除元素:\n";
    std::cout << "删除前的元素: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    numbers.erase(10); // 删除值为 10 的元素
    std::cout << "删除 10 后的集合大小: " << numbers.size() << std::endl; // 应该为 2 (20, 30)

    numbers.erase(50); // 尝试删除一个不存在的元素（没有效果）
    std::cout << "尝试删除 50 后的集合大小: " << numbers.size() << std::endl; // 仍然是 2

    std::cout << "删除 10 后的元素: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // --- 第二部分: 遍历和清空 ---
    std::cout << "\n--- 第二部分: 遍历和清空 ---\n";

    // 重新插入一些元素以供演示
    numbers.insert(100);
    numbers.insert(200);
    numbers.insert(50);

    // 5. 遍历集合（不保证顺序！）
    std::cout << "\n'numbers' 中的元素（顺序不保证，可能每次运行都不同）:\n";
    for (const int& num : numbers) { // 基于范围的 for 循环
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用显式迭代器遍历
    std::cout << "使用迭代器的元素（顺序仍不保证）:\n";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 6. 清空集合
    numbers.clear();
    std::cout << "\n清空后的集合大小: " << numbers.size() << std::endl; // 应该为 0

    // --- 第三部分: std::unordered_set<std::string> ---
    std::cout << "\n--- 第三部分: std::unordered_set<std::string> ---\n";

    std::unordered_set<std::string> names;
    names.insert("Bob");
    names.insert("Alice");
    names.insert("Alice"); // 重复元素，将被忽略
    names.insert("Charlie");

    std::cout << "集合中的姓名（顺序不保证）:\n";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    if (names.count("Bob")) {
        std::cout << "'Bob' 在集合中。\n";
    }

    names.erase("Charlie");
    std::cout << "删除 'Charlie' 后的姓名（顺序不保证）:\n";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    return 0; // 表示程序成功执行
}
