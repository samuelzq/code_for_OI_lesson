/**
 *
 * @File:   lower_bound.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-08
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int id;
    std::string name;

    // 自定义输出格式
    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << "{id: " << item.id << ", name: " << item.name << "}";
        return os;
    }
};

int main() {
    std::vector<Item> items = {
        {3, "Apple"},
        {1, "Banana"},
        {5, "Cherry"},
        {7, "Date"},
        {9, "Elderberry"}
    };

    // 按 id 排序（升序）
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.id < b.id;
    });

    // 目标 id
    int target_id = 6;

    // 使用 lower_bound 查找第一个 id >= target_id 的 Item
    auto it = std::lower_bound(
        items.begin(),
        items.end(),
        target_id,
        [](const Item& item, const int id) {
            return item.id < id; // 自定义比较器，按 id 比较
        }
    );

    if (it != items.end())
        std::cout << "Found item: " << *it << std::endl;
    else
        std::cout << "No item found with id >= " << target_id << std::endl;

    return 0;
}

