/**
 *
 * @File:   pair.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-02
 *
 */

#include <iostream>
#include <utility> // 包含 std::pair 和 std::make_pair
#include <string>
#include <vector>
#include <map>
#include <algorithm> // 包含 std::sort 和 std::minmax_element

int main() {
    // 1. 声明和初始化 pair 的不同方式
    std::cout << "--- 1. 声明和初始化 pair ---" << std::endl;
    std::pair<std::string, int> person1; // 默认构造
    person1.first = "Alice";
    person1.second = 30;
    std::cout << "person1: (" << person1.first << ", " << person1.second << ")" << std::endl;

    std::pair<char, double> data1 = {'A', 3.14}; // 直接初始化
    std::cout << "data1: (" << data1.first << ", " << data1.second << ")" << std::endl;

    auto person2 = std::make_pair("Bob", 25); // 使用 make_pair，自动推断类型
    std::cout << "person2: (" << person2.first << ", " << person2.second << ")" << std::endl;

    std::pair<int, float> point1 = {10, 2.5f}; // 使用列表初始化 (C++11 起)
    std::cout << "point1: (" << point1.first << ", " << point1.second << ")" << std::endl;

    // 2. 访问 pair 的元素
    std::cout << "\n--- 2. 访问 pair 的元素 ---" << std::endl;
    std::cout << "person1's name: " << person1.first << std::endl;
    std::cout << "person1's age: " << person1.second << std::endl;

    // 3. pair 的比较
    std::cout << "\n--- 3. pair 的比较 ---" << std::endl;
    std::pair<int, int> p1 = {1, 5};
    std::pair<int, int> p2 = {1, 10};
    std::pair<int, int> p3 = {2, 3};

    if (p1 < p2) {
        std::cout << "(" << p1.first << ", " << p1.second << ") < (" << p2.first << ", " << p2.second << ")" << std::endl;
    }
    if (p1 < p3) {
        std::cout << "(" << p1.first << ", " << p1.second << ") < (" << p3.first << ", " << p3.second << ")" << std::endl;
    }
    if (p2 > p3) {
        std::cout << "(" << p2.first << ", " << p2.second << ") > (" << p3.first << ", " << p3.second << ")" << std::endl;
    }
    if (p1 == std::make_pair(1, 5)) {
        std::cout << "(" << p1.first << ", " << p1.second << ") is equal to (1, 5)" << std::endl;
    }

    // 4. pair 在 vector 中的使用
    std::cout << "\n--- 4. pair 在 vector 中的使用 ---" << std::endl;
    std::vector<std::pair<std::string, int>> people;
    people.push_back({"Charlie", 35});
    people.push_back(std::make_pair("David", 28));
    people.emplace_back("Eve", 40); // C++11 引入，更高效的添加元素方式

    for (const auto& person : people) {
        std::cout << "Name: " << person.first << ", Age: " << person.second << std::endl;
    }

    // 对 vector<pair> 进行排序 (默认按 first 排序，first 相同时按 second 排序)
    std::sort(people.begin(), people.end());
    std::cout << "\nSorted people by name:" << std::endl;
    for (const auto& person : people) {
        std::cout << "Name: " << person.first << ", Age: " << person.second << std::endl;
    }

    // 5. pair 在 map 中的使用 (键值对)
    std::cout << "\n--- 5. pair 在 map 中的使用 ---" << std::endl;
    std::map<std::string, double> studentGrades;
    studentGrades.insert({"Frank", 85.5}); // 插入一个 pair
    studentGrades["Grace"] = 92.0;        // 使用 operator[] 插入或修改
    studentGrades.insert(std::make_pair("Heidi", 78.0));

    for (const auto& gradePair : studentGrades) {
        std::cout << "Student: " << gradePair.first << ", Grade: " << gradePair.second << std::endl;
    }

    // map 的迭代器返回的是 pair<const Key, Value>
    std::cout << "\nIterating through map using iterator:" << std::endl;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); ++it) {
        std::cout << "Student: " << it->first << ", Grade: " << it->second << std::endl;
    }

    // 6. pair 作为函数返回值
    std::cout << "\n--- 6. pair 作为函数返回值 ---" << std::endl;
    auto getMinMax = [](const std::vector<int>& nums) {
        if (nums.empty()) {
            return std::make_pair(-1, -1); // 返回一个表示错误的值
        }
        auto result = std::minmax_element(nums.begin(), nums.end());
        return std::make_pair(*result.first, *result.second);
    };

    std::vector<int> numbers = {5, 2, 8, 1, 9};
    std::pair<int, int> minMax = getMinMax(numbers);
    std::cout << "Min: " << minMax.first << ", Max: " << minMax.second << std::endl;

    std::vector<int> emptyNumbers;
    std::pair<int, int> emptyMinMax = getMinMax(emptyNumbers);
    std::cout << "Min (empty): " << emptyMinMax.first << ", Max (empty): " << emptyMinMax.second << std::endl;

    // 7. 嵌套的 pair
    std::cout << "\n--- 7. 嵌套的 pair ---" << std::endl;
    std::pair<std::string, std::pair<int, double>> complexData;
    complexData.first = "Item A";
    complexData.second.first = 100;
    complexData.second.second = 12.34;
    std::cout << "Complex Data: " << complexData.first << ", (" << complexData.second.first << ", " << complexData.second.second << ")" << std::endl;

    auto complexData2 = std::make_pair("Item B", std::make_pair(200, 56.78));
    std::cout << "Complex Data 2: " << complexData2.first << ", (" << complexData2.second.first << ", " << complexData2.second.second << ")" << std::endl;

    return 0;
}
