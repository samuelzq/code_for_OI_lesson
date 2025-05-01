/**
 *
 * @File:   binary_search_comp.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    int id;
    std::string name;
};

// 自定义比较器，按 id 排序
struct CompareById {
    bool operator()(const Person& a, const Person& b) const {
        return a.id < b.id;
    }
    bool operator()(const Person& a, int id) const {
        return a.id < id;
    }
    bool operator()(int id, const Person& a) const {
        return id < a.id;
    }
};

int main() {
    std::vector<Person> people = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};

    // 使用 lower_bound 查找 id 为 2 的人
    auto it = std::lower_bound(people.begin(), people.end(), 2, CompareById());

    if (it != people.end() && it->id == 2) {
        std::cout << "Person with id 2 found: " << it->name << std::endl;
    } else {
        std::cout << "Person with id 2 not found." << std::endl;
    }

    return 0;
}
